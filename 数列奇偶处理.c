/*����һ�������������β
������������ż����
��ͳ��������ż���ĸ���*/ 
#include <stdio.h>
int main(void)
{
 int num,sum1=0,sum2=0,i1=0,i2=0;
 scanf("%d",&num);
 while (num > 0)
 {
  if (num%2 != 0)
  {
   sum1 += num;
   i1++;
  }
  else
  {
  	sum2 += num;
  	i2++;
  }
  scanf("%d",&num);
 }
 printf("sum1=%d\nsum2=%d\n",sum1,sum2);
 printf("i1=%d\ni2=%d",i1,i2);
 return 0;
}
