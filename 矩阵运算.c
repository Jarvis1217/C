#include<stdio.h>
int main(void)
{
	int n,i,j;
	scanf("%d",&n);
	//申请n行n列数组 
	int num[n][n];
	//输入数据,i表示行，j表示列 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	//遍历矩阵，最后一行和最后一列不参与遍历过程
	//符合条件的数加入sum
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
