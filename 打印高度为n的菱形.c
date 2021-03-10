#include<stdio.h> 
int main(){
int n;
scanf("%d",&n);
int row=n/2;
int z=row+1;
int i,j;
for(i=1;i<=z;i++){
for(j=0;j<z-i;j++){
printf("  ");
}
for(j=0;j<i*2-1;j++){
printf("* ");
}
printf("\n");
}
for(i=1;i<=row;i++){
for(j=0;j<i;j++){
printf("  ");
}
for(j=0;j<(row-i)*2+1;j++){
printf("* ");
}
printf("\n");
}

return 0;
}
