#include <stdlib.h>
#include <stdio.h>

static void print_array(int a[], int length)
{
 int i =0;
 
 for(i=0;i<length;i++)
 printf("%d \t", a[i]);

printf("\n");

}

static unsigned int rotate(int a[], int length, int rotate)
{
 int i =0;
 int temp =0;
 length = length -1;
 for(i=0;i<rotate;i++)
 {
  temp = a[i];
  a[i] = a[length];
  a[length] = temp;                     
  length--;
 }
       
}

int main()
{
 int a[10] = {1,2,3,4,5,6,7,8,9,10};
 
 print_array(a, 10);    
 rotate(a, 10, 3);
 print_array(a, 10); 
 
getchar();
return 0;
}
