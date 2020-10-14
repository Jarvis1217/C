#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 
 char getPokerCard(int value)
 {
     if(value==1)
     {
         return 'A';
     }
    else if(value<10)
    {
        return value+'0';
    }
    else if(value==10)
    {
        return '0';
    }
    else if(value==11)
    {
        return 'J';
    }
    else if(value==12)
    {
        return 'Q';
    }
    else if(value==13)
    {
        return 'K';
    }
 }
 
 void printAnswer(int flag,int *poker,char *oper,char *answer)
 {
     char a=getPokerCard(poker[0]);
     char b=getPokerCard(poker[1]);
     char c=getPokerCard(poker[2]);
     char d=getPokerCard(poker[3]);
     
     switch(flag)
     {
         //1.((A*B)*C)*D
         case 1:
             printf("((%c%c%c)%c%c)%c%c\n",a,oper[0],b,oper[1],c,oper[2],d);
             break;
         //2.(A*(B*C))*D
         case 2:
             printf("(%c%c(%c%c%c))%c%c\n",a,oper[0],b,oper[1],c,oper[2],d);
             break;
         //3.(A*B)*(C*D)
         case 3:
             printf("(%c%c%c)%c(%c%c%c)\n",a,oper[0],b,oper[1],c,oper[2],d);
             break;
         //4.A*(B*(C*D))
         case 4:
             printf("%c%c(%c%c(%c%c%c))\n",a,oper[0],b,oper[1],c,oper[2],d);
             break;
         //5.A*((B*C)*D) 
         case 5:
             printf("%c%c((%c%c%c)%c%c)\n",a,oper[0],b,oper[1],c,oper[2],d);
             break;
         default:
             break;
     }
     
     //存储answer
     
     
     return ; 
 }
 
  double getValue(double num1,double num2,char oper)
 {
     double result;
     
     switch(oper)
     {
         case '+':
         result=num1+num2;
         break;
        case '-':
         result=fabs(num1-num2);
         break;
        case '*':
         result=num1*num2;
         break;
        case '/':
         result=num1/num2;
         break;
        default :
            break;
     }
     
     return result;
 }
 
 int getResult(int *poker,char *oper,char *answer)
 {
     double t;
     //将计算值取到 
     int a=poker[0]>10?1:poker[0];
     int b=poker[1]>10?1:poker[1];
     int c=poker[2]>10?1:poker[2];
     int d=poker[3]>10?1:poker[3];
     
     //穷举运算次序
    //1.((A*B)*C)*D
    t=0;
    t=getValue(a,b,oper[0]);
    t=getValue(t,c,oper[1]);
    t=getValue(t,d,oper[2]);
    
    if(fabs(t-24)<0.0001)
    {
        printAnswer(1,poker,oper,answer);
        return 1;
    }
    
    //2.(A*(B*C))*D
    t=0;
    t=getValue(b,c,oper[1]);
    t=getValue(a,t,oper[0]);
    t=getValue(t,d,oper[2]);
    
    if(fabs(t-24)<0.0001)
    {
        printAnswer(2,poker,oper,answer);
        return 1;
    }
    
    //3.(A*B)*(C*D)
    t=0;
    t=getValue(getValue(a,b,oper[0]),getValue(c,d,oper[2]),oper[1]);
    
    if(fabs(t-24)<0.0001)
    {
        printAnswer(3,poker,oper,answer);
        return 1;
    }
    
    //4.A*(B*(C*D))
    t=0;
    t=getValue(c,d,oper[2]);
    t=getValue(b,t,oper[1]);
    t=getValue(a,t,oper[0]);
    
    if(fabs(t-24)<0.0001)
    {
        printAnswer(4,poker,oper,answer);
        return 1;
    }
    
    //5.A*((B*C)*D) 
    t=0;
     t=getValue(b,c,oper[1]);
    t=getValue(t,d,oper[2]);
    t=getValue(a,t,oper[0]);
    
    if(fabs(t-24)<0.0001)
    {
        printAnswer(5,poker,oper,answer);
        return 1;
    }
    
     return 0;
 }
 
 void printResult(int *poker,char *answer)
 {
     char OperKey[4]={'+','-','*','/'};
     char oper[3];
     int i,j,k;
     int count=0;
     
     for(i=0;i<4;i++)
     for(j=0;j<4;j++)
     for(k=0;k<4;k++)
     {
         oper[0]=OperKey[i];
         oper[1]=OperKey[j];
         oper[2]=OperKey[k];
         
         if(getResult(poker,oper,answer))
         count++;
     }
     if(count)
     {
         printf("共%d种解法\n",count);
     }
     else
     {
         printf("该情况无解\n");
     }
     
     return ;
 }
 
   void printPoker(int *poker)
 {    
     int i;
     for(i=0;i<4;i++)
     {
         printf("%c ",getPokerCard(poker[i]));
     }
     printf("\n");
     
     return ;
 }
 
 void getRandomPokers(int *poker)
 {
     int i;
     
     //利用系统时间作为种子产生随机数 ，函数srand()，rand()=>stdlib.h ，函数time()=>time.h 
    srand((unsigned)time(NULL));
    for(i=0;i<4;i++)
    {
        poker[i]=rand()%12+1;
    }
    
    return ;    
 }
 
 main()
 {   
     int poker[4];
     char answer[20];
     char c;
     
     printf("纸牌计算24点\n--------------------------------------------\n");
     do
     {
         //生成随机纸牌 
         getRandomPokers(poker);
         
         printf("随机生成的纸牌为：\n");
 
         //输出生成的纸牌 
         printPoker(poker);
         
         printf("\n任意键获得结果...\n");
         getchar(); 
         
         //输出计算结果
         printResult(poker,answer);
         
         printf("\n回车键继续，其他键并回车退出...\n");
         c=getchar();
         
         printf("--------------------------------------------\n");
     }
     while(c=='\n');
     
     return 0;
 }
