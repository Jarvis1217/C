#include<stdio.h>
#include<math.h>
int main(void)
{
	int N,sum=0,i=0;
	scanf("%d",&N);
	while(N!=0) //���Ϸ������λ
    {
      sum += N%10;
      N /= 10;
      i++;
    }
    printf("%d %d\n",i,sum);
    return 0;
} 
