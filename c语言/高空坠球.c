#include<stdio.h>
int main(void)
{
	double highstart,highend=0;
	scanf("%lf",&highstart);
	double distance=highstart;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		distance+=highend*2;
		highstart=highstart/2;
        highend=highstart;
	}
	printf("%.1lf %.1lf",distance,highend);
	return 0;
}
