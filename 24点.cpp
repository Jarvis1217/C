#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//生成随机数组 
void get_num(int *num_list)
{
	int i;
	srand(time(0));
	for(i=0;i<4;i++)
	{
		num_list[i]=rand()%9+1;
	}
}

//输出随机数组
void print_num(int *num_list)
{
	int i;
	for(i=0;i<4;i++)
	{
		printf("%d ",num_list[i]);
	}
	printf("\n");
} 

//计算
 double get_Value(double num1,double num2,char op)
 {
 	double result;
 	
 	switch(op)
 	{
 		case '+':result=num1+num2;break;
 		case '-':result=fabs(num1-num2);break;
 		case '*':result=num1*num2;break;
 		case '/':result=num1/num2;break;
 		default:break;
	}
	
	return result;
 }

//打印符合条件的算式
void print_answer(int flag,int *num_list,char *op)
{
	int a=num_list[0];
	int b=num_list[1];
	int c=num_list[2];
	int d=num_list[3];
	
	switch(flag)
	{
		//1、((A*B)*C)*D
		case 1:
			printf("((%d%c%d)%c%d)%c%d\n",a,op[0],b,op[1],c,op[2],d);
			break;
		//2、(A*(B*C))*D
		case 2:
			printf("(%d%c(%d%c%d))%c%d\n",a,op[0],b,op[1],c,op[2],d);
			break;
		//3、(A*B)*(C*D)
		case 3:
			printf("(%d%c%d)%c(%d%c%d)\n",a,op[0],b,op[1],c,op[2],d);
			break;
		//4、A*(B*(C*D))
		case 4:
			printf("%d%c(%d%c(%d%c%d))\n",a,op[0],b,op[1],c,op[2],d);
			break;
		//5、A*((B*C)*D)
		case 5:
			printf("%d%c((%d%c%d)%c%d)\n",a,op[0],b,op[1],c,op[2],d);
			break;
		default:
			break;
	}
}

//构建数学表达式
int calc_24(int *num_list,char *op)
{
	int a=num_list[0];
	int b=num_list[1];
	int c=num_list[2];
	int d=num_list[3];
	double t;
	
	//1、((A*B)*C)*D
	t=0;
	t=get_Value(a,b,op[0]);
	t=get_Value(t,c,op[1]);
	t=get_Value(t,d,op[2]);
	if(fabs(t-24)<0.0001)
	{
		print_answer(1,num_list,op);
		return 1;
	}
	
	//2、(A*(B*C))*D
	t=0;
	t=get_Value(b,c,op[1]);
	t=get_Value(t,a,op[0]);
	t=get_Value(t,d,op[2]);
	if(fabs(t-24)<0.0001)
	{
		print_answer(2,num_list,op);
		return 1;
	} 
	
	//3、(A*B)*(C*D)
	t=0;
	t=get_Value(get_Value(a,b,op[0]),get_Value(c,d,op[2]),op[1]);
	if(fabs(t-24)<0.0001)
	{
		print_answer(3,num_list,op);
		return 1;
	}
	
	//4、A*(B*(C*D))
	t=0;
	t=get_Value(c,d,op[2]);
	t=get_Value(b,t,op[1]);
	t=get_Value(a,t,op[0]);
	if(fabs(t-24)<0.0001)
	{
		print_answer(4,num_list,op);
		return 1;
	}
	
	//5、A*((B*C)*D)
	t=0;
    t=get_Value(b,c,op[1]);
    t=get_Value(t,d,op[2]);
    t=get_Value(a,t,op[0]);   
    if(fabs(t-24)<0.0001)
    {
        print_answer(5,num_list,op);
        return 1;
    }
	
	return 0; 
}

//打印结果 
void print_result(int *num_list)
{
	char symbols[4]={'+','-','*','/'};
	char op[3];
	int i,j,k;
	int count=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				op[0]=symbols[i];
				op[1]=symbols[j];
				op[2]=symbols[k];
				
				if(calc_24(num_list,op))
				count++;
			}
		}
	}	
	if(count)
	{
		printf("\n此数列共有%d种解",count);
	}
	else
	{
		printf("此数列无解");
	}
} 

int main(void)
{
	//生成随机数列 
	int num_list[4];
	get_num(num_list);
	
	//输出随机数列 
	printf("随机数组为:\n");
	print_num(num_list);
	
	printf("\n按任意键查看答案...\n");
	getchar();
	
	//输出计算结果
	print_result(num_list);
} 
