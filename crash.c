#include<stdio.h>
#include<stdlib.h>


int main ()
{
char *p;
strcpy(p, "abc");//crash here
printf("%s", p);
getchar();

return 0;
}
