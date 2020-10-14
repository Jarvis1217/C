#include<stdio.h>
int main(void)
{
	int n,count=0,i=1,a;
	
	float sum=0,average;
	scanf("%d",&n);
	do{
		scanf("%d",&a);
		if(a>=60)
	    	count++;
		sum+=a;
		i++;
	}while(i<=n);
	average=sum/n;
	printf("average = %.1f\n",average);
	printf("count = %d\n",count);
	return 0;
}
