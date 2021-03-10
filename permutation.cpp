#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void permutation(int a[],int index,int size)
{
	if(index==size)
	{
		int result[size];
		int i;
		for(i=0;i<size;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		int j;
		for(j=index;j<size;j++)
		{
			swap(&a[j],&a[index]);
			permutation(a,index+1,size);
			swap(&a[j],&a[index]);
		}
	}

}

int main(void)
{
	int num_list[4],i;
	srand(time(0));
	//生成随机数 
	for(i=0;i<4;i++)
	{
		num_list[i]=rand()%9+1;
	}
	//输出随机数组 
	printf("随机数组为:");
	for(i=0;i<4;i++)
	{
		printf("%d ",num_list[i]);
	}
	printf("\n排序结果为:\n");
	
	permutation(num_list,0,4);
	
	return 0;
} 
