#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
 
#define Height 25  //�Թ��ĸ߶�
#define Width 25  //�Թ��Ŀ��
#define Wall 1
#define Road 0
#define Start 2
#define End 3 
#define Up 1
#define Down 2
#define Left 3
#define Right 4
int map[Height+2][Width+2];
void gotoxy(int x,int y) //�ƶ�����
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden()//���ع��
{
    CONSOLE_CURSOR_INFO csi={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csi);
}
void create(int x,int y) //��������Թ�
{
    int c[4][2]={0,1,1,0,0,-1,-1,0}; //�ĸ�����
    int i,j,t;
        //���������
    for(i=0;i<4;i++)
    {
        j=rand()%4;
        t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
        t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
    }
    map[x][y]=Road;
    for(i=0;i<4;i++)
    if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
    {
        map[x+c[i][0]][y+c[i][1]]=Road;
        create(x+2*c[i][0],y+2*c[i][1]);
    }
}
int get_key() //���հ���
{
    char c;
    while(c=getch())
    {
        c=getch();
        if(c==72) return Up; //��
        if(c==80) return Down; //��
        if(c==75) return Left; //��
        if(c==77) return Right; //��
    }
    return 0;
}
void paint(int x,int y) //���Թ�
{
    gotoxy(2*y-2,x-1);
    switch(map[x][y])
    {
        case Start:
        printf("->");break; //�����
        case End:
        printf("->");break; //������
        case Wall:
        printf("�~");break; //��ǽ
        case Road:
        printf(" ");break; //��·
    }
}
void game()
{
    int x=2,y=1; //��ҵ�ǰλ�ã��տ�ʼ����ڴ�
    int c; //�������հ���
    while(1)
    {
        gotoxy(2*y-2,x-1);
        printf("��"); //������ҵ�ǰλ��
        if(map[x][y]==End) //�ж��Ƿ񵽴����
        {
            gotoxy(Height+5,Width);
            printf("�����յ㣬�����������");
            getch();
            break;
        }
        c=get_key();
        switch(c)
        {
            case Up: //������
            if(map[x-1][y]!=Wall)
            {
                paint(x,y);
                x--;
            }
            break;
            case Down: //������
            if(map[x+1][y]!=Wall)
            {
                paint(x,y);
                x++;
            }
            break;
            case Left: //������
            if(map[x][y-1]!=Wall)
            {
                paint(x,y);
                y--;
            }
            break;
            case Right: //������
            if(map[x][y+1]!=Wall)
            {
                paint(x,y);
                y++;
            }
            break;
        }
    }
}
int main()
{
	system("title �Թ�");
    int i,j;
    srand((unsigned)time(NULL)); //��ʼ���漴����
    hidden(); //���ع��
    for(i=0;i<=Height+1;i++)
    for(j=0;j<=Width+1;j++)
    if(i==0||i==Height+1||j==0||j==Width+1) //��ʼ���Թ�
    map[i][j]=Road;
    else map[i][j]=Wall;
 
    create(2,2);//��һ���㿪ʼ�����Թ�
    for(i=0;i<=Height+1;i++) //�߽紦�� 
    {
        map[i][0]=Wall;
        map[i][Width+1]=Wall;
    }
 
    for(j=0;j<=Width+1;j++) //�߽紦��
    {
        map[0][j]=Wall;
        map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //�������
    map[Height-1][Width]=End; //��������
    for(i=1;i<=Height;i++)
    for(j=1;j<=Width;j++) //�����Թ�
		paint(i,j);	
    game(); //��ʼ��Ϸ
    getch();
    return 0;
} 
