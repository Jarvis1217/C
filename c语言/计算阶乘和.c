#include<stdio.h>

int main()

{
int n,i,t=1,s=0;

scanf("%d",&n);

for(i=1;i<=n;i++)

{t*=i;

s+=t;

}

printf("%d",s);

return 0;

}
