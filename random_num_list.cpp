#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(void)
{
	int num_list[4],i;
	srand(time(0));
	//��������� 
	for(i=0;i<4;i++)
	{
		num_list[i]=rand()%9+1;
	}
	//��� 
	for(i=0;i<4;i++)
	{
		printf("%d ",num_list[i]);
	}
		
	return 0;
}
