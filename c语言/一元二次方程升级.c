/*1)�����������������ȵ�ʵ��������ÿ�����һ�������ȴ��С��

2)�����������������ȸ���������ÿ�а��ո�ʽ��ʵ��+�鲿i�����һ������������鲿Ϊ���ģ�������鲿Ϊ���ģ�

3)�������ֻ��һ��������ֱ������˸���

4)���ϵ����Ϊ0�������"Zero Equation"��

5)���a��bΪ0��c��Ϊ0�������"Not An Equation"*/ 
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
