#include<stdio.h>

void qsort(int *list,int len)
{
	int i=0,j=len-1,key=list[0];
	if(len>1)
	{
		while(i!=j)
		{
			for(j=len-1;i<j;j--)
			{
				if(list[j]<key)
				{
					list[i]=list[j];
					break;
				}
			}
			for(i=0;i<j;i++)
			{
				if(list[i]>key)
				{
					list[j]=list[i];
					break;
				}
			}
			list[i]=key;
		}
		qsort(list,i);
		qsort(list+i+1,len-i-1);
	}
}

int main(void)
{
	int num_list[9]={9,8,7,6,5,4,3,2,1};
	int i;
	
	printf("原数列为:");
	for(i=0;i<9;i++)
	{
		printf("%d ",num_list[i]);
	}
	
	qsort(num_list,9);
	
	printf("\n排序后的数列为:");
	for(i=0;i<9;i++)
	{
		printf("%d ",num_list[i]);
	}
	
	return 0;
}
