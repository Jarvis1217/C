#include<stdio.h>
double cylinder(double r,double h);
int main(void)
{
	double r,h,v;
	scanf("%lf%lf",&r,&h);
	v=cylinder(r,h);
	printf("v=%lf",v);
	return 0;
}
double cylinder(double r,double h)
{
	double v;
	v=3.1415926*r*r*h;
	return v;
}
