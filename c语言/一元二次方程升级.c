/*1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；

2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；

3)如果方程只有一个根，则直接输出此根；

4)如果系数都为0，则输出"Zero Equation"；

5)如果a和b为0，c不为0，则输出"Not An Equation"*/ 
#include <stdio.h>
#include <math.h>
int main()
{
float a,b,c;
while(scanf("%f%f%f",&a,&b,&c)!=EOF)
{
if(a==0 && b==0 && c==0)
printf("Zero Equation\n");
else
{
float x,x1,x2,m;
if(a==0 && b==0 && c!=0)
printf("Not An Equation\n");
   if(a==0 && b!=0 && c!=0)
printf("%.2f\n",-c/b);
if(a!=0 && b!=0)
{
if(b*b-4*a*c==0)
{
m=-b/(2*a);
printf("%.2f\n",m);
}
if(b*b-4*a*c>0)
{
x=sqrt(b*b-4*a*c);
x1=(-b+x)/(2*a);
x2=(-b-x)/(2*a);
printf("%.2f\n",x1);
printf("%.2f\n",x2);
}
if(b*b-4*a*c<0)
{
x=sqrt(4*a*c-b*b);
x1=-b/(2*a);
x2=x/(2*a);
printf("%.2f+%.2fi\n",x1,x2);
printf("%.2f-%.2fi\n",x1,x2);
}
}
if(a!=0 && b==0 && c!=0)
{
printf("0.00+%.2fi\n",sqrt(c/a));
printf("0.00-%.2fi\n",sqrt(c/a));
}
if(a!=0 && b==0 && c==0 )
printf("0.00\n");
}
}
return 0;
}
