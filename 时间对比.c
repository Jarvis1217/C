#include<stdio.h>
#include<time.h>
float Addtime1(int n);
float Addtime2(int n);
int main()
{  long n;
   printf("n(����1000000):");
   scanf("%d",&n);
   if(n<1000000)
     return 0;
   Addtime1(n);
   Addtime2(n); 
   return 1;
}
float Addtime1(int n){
	clock_t t;
    t=clock();
	int i,s;
	s=0;
	for(i=0;i<=n;i++){
		s=s+i;
	}
	printf("����1:\n");
	printf("���1~%d֮��:%d\n",n,s);
	t=clock()-t;
	printf("��ʱΪ��%lf��\n", ((float)t/CLOCKS_PER_SEC));
}
float Addtime2(int n){
	clock_t t;
	t=clock();
    int h;
    h=(n*(n+1)/2);
	printf("����2:\n");
	printf("���1~%d֮��:%d\n",n,h);
	t=clock()-t;
	printf("��ʱΪ��%lf��\n", ((float)t/CLOCKS_PER_SEC));
}
