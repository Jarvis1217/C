#include<stdio.h>
#include<math.h> 
int main (void)
{
	char c;
	double a,b;
    scanf("%lf%c%lf",&a,&c,&b);
	switch(c)
	{
		case'+':printf("result=%lg\n",a+b);break;
		case'-':printf("result=%lg\n",a-b);break;
		case'*':printf("result=%lg\n",a*b);break;
		case'/':printf("result=%lg\n",a/b);break;
		case'^':printf("result=%lg\n",pow(a,b));break;
		default:printf("error\n");break;
	}
	return 0;
}
