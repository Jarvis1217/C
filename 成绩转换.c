#include<stdio.h>
int main (void)
{
	int grade;
	scanf("%d",&grade);
	int t;
	t=grade/10;
	switch(t)
	{
		case 9:printf("A\n");break;
		case 8:printf("B\n");break;
		case 7:printf("C\n");break;
		case 6:printf("D\n");break;
		case 5:printf("E\n");break;
		case 4:printf("E\n");break;
		case 3:printf("E\n");break;
		case 2:printf("E\n");break;
		case 1:printf("E\n");break;
		case 0:printf("E\n");break;
		default:printf("error\n");break;
	}
	return 0;
} 
