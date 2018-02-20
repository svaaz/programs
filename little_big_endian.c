#include<stdio.h>

int main (void)
{
    
    char p =1;
    
    /* assigning integer to char */
    
    /* in Big endian system 1 will be represented as 
    
    0x 01 00 00 00
    
    in Little endian system it will be 
    
    0x 00 00 00 01
    
    so when you assign the char p with 1
    
    in little Endian machine 1 will be assigned 
    
    in the Big-Endian machine 0 will be assigned in the lsb!
    
    */
    
    if(p&1)
    printf("\n Little Endian");
    else
    printf("\n Big Endian");
    
}
