#include<stdio.h>
int main(void)
{
	int M,N,j,k;/*k�����Լ��*/ 
	do{
		scanf("%d%d",&M,&N);
	}while(M>1000||N>1000);
	j=M;
	while(j%N!=0)
	j=j+M;
	k=(M*N)/j;
	printf("%d %d",k,j);/*j����С������*/ 
	return 0;
} 
