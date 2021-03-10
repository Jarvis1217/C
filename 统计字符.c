#include<stdio.h>
int main(void)
{
  int letter=0,blank=0,digit=0,other=0;
  int i=1;
  char c;
  for(i=1;i<=10;i++)
  {
    c=getchar();
    
    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
	{ 
     letter++;
	}
	else
	{
      	if(c >= '0' && c <= '9')
      	{
           digit++;
      	}
      	else
      	{
              if(c==' '||c=='\n')
              {
                 blank++;
              }
               else
              {
                  other++;
              }
       	}
	}
  }
  printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
}
