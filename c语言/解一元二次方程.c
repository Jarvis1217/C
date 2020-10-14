#include<stdio.h>
#include<math.h>
int main(void)
{
	int a,b,c,d;
	double x1,x2,x;
	printf("input a,b,c\n");
	scanf("%d%d%d",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0)
	{
		printf("此函数无解\n");
	}
	else if(d==0)
	{
		x=-b/2*a;
		printf("x1=x2=%lg",x);
	}
	else if(d>0)
	{
		x1=-b+sqrt(d)/(2*a);
		x2=-b-sqrt(d)/(2*a);
		printf("x1=%lg\nx2=%lg",x1,x2);
	}
	return 0;
}
