/*三天打鱼两天晒网*/ 
#include<stdio.h>
int main(void)
{
	int N;
	N<1000||N==1000;
	scanf("%d",&N);
	int t;
	t=N%5;
	if(t<=3)
	printf("Fishing in day %d",N);
	else if(t>3)
	printf("Drying in day %d",N);
	return 0;
}
