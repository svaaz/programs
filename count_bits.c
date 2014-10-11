#include<stdio.h>
#include<stdlib.h>


static int count_set_bits(int number)
{

 unsigned int counter = 0 ;
 
 for( ;number !=0;number=number>>1)
 {
   if(number&1)
   {
       counter ++; 
   }       
 }
 
 return counter;
}

int main()
{
    int a =7;
    
    printf("bits set are : %d",count_set_bits(a));
    getchar();
}
