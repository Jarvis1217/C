#include<stdio.h>
int main(void)
{
	int n,i,j;
	scanf("%d",&n);
	//����n��n������ 
	int num[n][n];
	//��������,i��ʾ�У�j��ʾ�� 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	//�����������һ�к����һ�в������������
	//����������������sum
	int sum=0; 
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if((i+j)!=(n-1))
			{
				sum=sum+num[i][j];
			}
		}
	}
	printf("%d",sum);
	return 0;
} 
