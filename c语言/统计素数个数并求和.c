#include<stdio.h>
int main(void)
{
	int M,N,i,k;
	int count=0;
	int sum=0;
	do
	{
		scanf("%d%d",&M,&N);
	}while((M<1||N>500)&&N<M);
	for(i=M;i<=N;i++)
	{
		for(k=2;k<=i-1;k++)
		{
			if(i%k==0)
		    	break;	
		}
      if(k>=i)
	  {
       	count++;
		sum+=i;
	  }
	}
	printf("%d %d\n",count,sum);
	return 0;
}
