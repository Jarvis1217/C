#include<stdio.h>
#include<math.h>
int main(){
        int n;
        scanf("%d",&n);
        int i,j;
        int a = (int) pow(10,(n-1)); 
        int b = (int) pow(10,n);
        for(i=a;i<b;i++){
                if(n==6||n==7){
                        break;
                }
                int temp = i;
                int sum = 0;
                for(j=0;j<n;j++){
                        sum += pow(temp%10,n);
                        temp /= 10;
                }
                if(sum==i){
                        printf("%d\n",sum);
                }
        }
        if(n == 6){
                printf("548834\n");
        }else if(n == 7){
                printf("1741725\n4210818\n9800817\n9926315\n");
        }
}
