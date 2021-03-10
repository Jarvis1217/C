
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
 
#define MAXQSIZE 1000
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
 
#define N 37	
#define M 47
#define DELAY 1
 
#define MAXQSIZE 1000
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
 
typedef enum { MASK = 0, ROAD = 1, BACK = 2, INWALL = 3, OUTWALL = 4, EMPTYWALL = 5 } BlockType;
typedef enum { EAST = 6, SOUTH = 7, WEST = 8, NORTH = 9 } Direction;
typedef int Maze;
 
bool visited[N][M];
bool mask[N][M];
bool area[N][M];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
 
typedef struct
{
	int x;
	int y;
	int di;
}Block;
 
typedef struct {
 
	Block *base;
	int front;
	int rear;
}SqQueue;
 
typedef struct
{
	Block *base;
	Block *top;
	int stacksize;
}SqStack;
 
void initStack(SqStack &S)
{
	S.base = (Block*)malloc(STACK_INIT_SIZE * sizeof(Block));
	if (!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
 
void push(SqStack &S, Block e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (Block*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Block));
		if (!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
}
 
void pop(SqStack &S, Block&e)
{
	if (S.top == S.base)
		return;
	S.top--;
	e = *S.top;
}
 
bool isEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}
 
void initQueue(SqQueue &Q)
{
	Q.base = (Block*)malloc(MAXQSIZE * sizeof(Block));
	if (!Q.base)
		return;
	Q.front = Q.rear = 0;
}
 
void enQueue(SqQueue &Q, Block e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
 
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}
 
int getLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
 
void deQueue(SqQueue &Q, Block &e)
{
	if (Q.front == Q.rear)
		return;
	srand((unsigned)time(NULL));
	int randIdx = rand() % getLength(Q);
	e = Q.base[randIdx];
	Q.base[randIdx] = Q.base[Q.rear - 1];
	Q.base[Q.rear - 1] = e;
 
	Q.rear = (Q.rear - 1) % MAXQSIZE;
}
 
bool isEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
 
void initMaze(Maze maze[N][M], Block &in, Block &out);
void findPath(Maze maze[N][M], Block in, Block out);
void initBlock(Block &block, int x, int y, int di);
void showBlock(Maze maze[N][M]);
void updateMaze(Maze maze[N][M]);
int nextBlockX(int a, int di);
int nextBlockY(int b, int di);
bool inMaze(int x, int y);
void clearMask(int x, int y);
void gotoxy(int x, int y);
void hideCursor();
void initHeart();
 
int main()
{
	Maze maze[N][M];
	Block in, out;
	initMaze(maze, in, out);
	findPath(maze, in, out);
	return 0;
}
 
void initMaze(Maze maze[N][M], Block &in, Block &out)
{
	initHeart();
	srand((unsigned)time(NULL));
 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area[i][j] && !(area[i][j - 1] && area[i][j + 1] && area[i - 1][j] && area[i + 1][j]))
				maze[i][j] = OUTWALL;
			else if (area[i][j] && i % 2 == 0 && j % 2 == 0)
				maze[i][j] = ROAD;
			else if (area[i][j])
				maze[i][j] = INWALL;
			else
				maze[i][j] = EMPTYWALL;
			visited[i][j] = false;
			mask[i][j] = true;
		}
	}
	in.x = 1;
	in.y = 6;
	out.x = 27;
	out.y = 36;
	maze[in.x][in.y] = maze[out.x][out.y] = ROAD;
	SqQueue S;
	Block start;
	initQueue(S);
	start.x = 2;
	start.y = 6;
	enQueue(S, start);
	visited[start.x][start.y] = true;
	clearMask(start.x, start.y);
	while (!isEmpty(S))
	{
		Block curBlock;
		deQueue(S, curBlock);
		for (int i = 0; i < 4; i++)
		{
			int nextBlockX = curBlock.x + di[i][0] * 2;
			int nextBlockY = curBlock.y + di[i][1] * 2;
			if (inMaze(nextBlockX, nextBlockY) && maze[nextBlockX][nextBlockY] == ROAD && !visited[nextBlockX][nextBlockY])
			{
				Block nextBlock;
				nextBlock.x = nextBlockX;
				nextBlock.y = nextBlockY;
				enQueue(S, nextBlock);
				maze[curBlock.x + di[i][0]][curBlock.y + di[i][1]] = ROAD;
				visited[nextBlockX][nextBlockY] = true;
				clearMask(nextBlockX, nextBlockY);
				updateMaze(maze);
			}
		}
	}
 
	for (int ii = 0; ii < N; ii++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[ii][j] == OUTWALL)
			{
				mask[ii][j] = false;
				updateMaze(maze);
			}
		}
	}
}
 
void findPath(Maze maze[N][M], Block in, Block out)
{
	Block block;
	SqStack S;
	initStack(S);
	int curBlockX = in.x;
	int curBlockY = in.y;
	int step = 1;
	do {
		if (inMaze(curBlockX, curBlockY) && maze[curBlockX][curBlockY] == ROAD)
		{
			initBlock(block, curBlockX, curBlockY, EAST);
			push(S, block);
 
			maze[curBlockX][curBlockY] = block.di;
			updateMaze(maze);
 
			if (curBlockX == out.x&&curBlockY == out.y)
			{
				printf("\nѰ·�ɹ�\n��%d��", step);
				Sleep(10000);		//����10s
				system("cls");
				return;
			}
			curBlockX = nextBlockX(block.x, block.di);
			curBlockY = nextBlockY(block.y, block.di);
			step++;
		}
		else
		{
			pop(S, block);
 
			if (block.di < NORTH)
			{
				block.di++;
				maze[block.x][block.y] = block.di;
				push(S, block);
				curBlockX = nextBlockX(block.x, block.di);
				curBlockY = nextBlockY(block.y, block.di);
				updateMaze(maze);
			}
			else
			{
				maze[block.x][block.y] = BACK;
				updateMaze(maze);
				step--;
			}
		}
	} while (!isEmpty(S));
	printf("Ѱ·ʧ��");
}
 
void initBlock(Block &block, int x, int y, int di)
{
	block.x = x;
	block.y = y;
	block.di = di;
}
 
void showBlock(Maze maze[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (mask[i][j] == true)
				printf("  ");
			else if (maze[i][j] == INWALL)
				printf("��");
			else if (maze[i][j] == OUTWALL)
				printf("��");
			else if (maze[i][j] == EMPTYWALL)
				printf("  ");
			else if (maze[i][j] == ROAD)
				printf("  ");
			else if (maze[i][j] == BACK)
				printf("��");
			else if (maze[i][j] == EAST)
				printf("��");
			else if (maze[i][j] == SOUTH)
				printf("��");
			else if (maze[i][j] == WEST)
				printf("��");
			else if (maze[i][j] == NORTH)
				printf("��");
			if (j != 0 && j % (M - 1) == 0)
				printf("\n");
		}
	}
}
 
void updateMaze(Maze maze[N][M])
{
	hideCursor();
	gotoxy(0, 0);
	showBlock(maze);
	Sleep(1);           
}
 
int nextBlockX(int a, int di)
{
	int x = a;
	switch (di)
	{
		case SOUTH:
			x++;
			break;
		case NORTH:
			x--;
			break;
		default:
			break;
	}
	return x;
}
 
int nextBlockY(int b, int di)
{
	int y = b;
	switch (di)
	{
		case EAST:
			y++;
			break;
 
		case WEST:
			y--;
			break;
		default:
			break;
	}
	return y;
}
 
bool inMaze(int x, int y)
{
	return x >= 0 && x < N&&y >= 0 && y < M;
}
 
void clearMask(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (inMaze(i, j))
				mask[i][j] = false;
}
 
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
 
void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
 
void initHeart()
{
	int i = 0, j = 0;
	for (float y = 1.2f; y > -1.0f; y -= 0.06f)
	{
		for (float x = -1.1f; x < 1.2f; x += 0.05f)
		{
			float a = x * x + y * y - 1;
			if (a * a * a - x * x * y * y * y <= 0.0f)
				area[i][j] = true;
			else
				area[i][j] = false;
			j++;
		}
		i++;
		j = 0;
	}
} 
