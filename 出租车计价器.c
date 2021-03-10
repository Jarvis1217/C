/*起步里程为3公里，起步费10元；
超起步里程后10公里内，每公里2元；
超过10公里以上的部分加收50%的回空补贴费，即每公里3元；
营运过程中，因路阻及乘客要求临时停车的，按每5分钟2元计收（不足5分钟则不收费）。*/ 
#include<stdio.h>
int main(void)
{
	double km;
	int minute;
	scanf("%lf%d",&km,&minute);/*输入里程与等待时间*/ 
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
	printf("%.lf",money);/*输出钱数*/ 
	return 0;
}
