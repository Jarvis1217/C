/*s=a+aa+aaa*/ 
#include<stdio.h>
int main(void)
{
	int a,n,i,s=0,t=0;
	do{
		scanf("%d%d",&a,&n);
	}while(a>9||n>9);
	for(i=1;i<=n;i++)
	{
	  t=t*10+a;
	  s+=t;
	}
	printf("s = %d",s);
	return 0;
}
