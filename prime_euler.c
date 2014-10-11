#include<stdio.h>
#define true 1
#define false 0
void main()
{
 unsigned int i =0;
 unsigned int j =0;
 unsigned int flag = false;
 long long sum =0;
 
printf("\n Hi");

for (i =2;i<2000000;i++)
{
 flag = false;
   
 for(j=2;j<i;j++)
 {
   if(i % j == 0)
   {
    flag = false;
    break; 
    }
    flag = true;                  
 }
 if(flag)
 {
 //printf("\n %d is a prime", i);
 printf(".");
 sum+= i;
 
 }
}
printf("\n %lld ", sum);
getch();
getch();
}
