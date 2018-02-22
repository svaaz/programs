#include<stdio.h>

char revBits(char a)
{

    char temp = 0x0;

    while(a)
    {
        temp = temp << 1;
        temp |= a & 0x1 ;
        a = a>>1;
    }

    return temp;
}

int main()
{

    char a ='g';

    printf("%c\r\n", revBits(a));

}
