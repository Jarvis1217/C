/*�����Ϊ3����𲽷�10Ԫ��
������̺�10�����ڣ�ÿ����2Ԫ��
����10�������ϵĲ��ּ���50%�Ļؿղ����ѣ���ÿ����3Ԫ��
Ӫ�˹����У���·�輰�˿�Ҫ����ʱͣ���ģ���ÿ5����2Ԫ���գ�����5�������շѣ���*/ 
#include<stdio.h>
int main(void)
{
	double km;
	int minute;
	scanf("%lf%d",&km,&minute);/*���������ȴ�ʱ��*/ 
	double money,money1,money2;
	if(km<=3)
	{
		money1=10; 
	} 
	else
	{
		if(km<=10&&km>3)
		{
			money1=(km-3)*2+10;
		}
		else
		{
			money1=(km-10)*3+24;
		}
	}
	if(minute>=5)
	{
		money2=(minute/5)*2;
	}
	else
	{
		money2=0;
	}
	money=(int)(money1+money2+0.5);
	printf("%.lf",money);/*���Ǯ��*/ 
	return 0;
}
