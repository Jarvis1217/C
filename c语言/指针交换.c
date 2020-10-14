#include<stdio.h>
change(int *p1,int *p2);
int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	change(&a,&b);
	printf("a=%d\nb=%d",a,b);
	return 0;
}
//change
change(int *p1,int *p2){
	int tem;
	tem=*p1;
	*p1=*p2;
	*p2=tem;
}
