#include<stdio.h>
int main(void)
{
  int i,min,n,x;
  scanf("%d",&n);
  scanf("%d",&x);
  min=x;
  for(i=1;i<n;i++)
  {
    scanf("%d",&x);
    if(min>x)
    min=x;
  }
  printf("min = %d\n",min);
  return 0;
}
