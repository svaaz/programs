#include <stdlib.h>
#include <stdio.h>

static unsigned int binsearch(int a[], int key,int low, int high)
{
     
       unsigned int mid =0;
              
              if(high<low)
              {
               return -1; 
              }
       mid = (low+high)/2;
       
       if(a[mid] > key )
       {
        return  binsearch(a, key, low, mid-1);         
       }
       else if(a[mid] < key )
       {
        return binsearch(a, key, mid+1, high);
       }
       else
       {
        return mid;
       }
}
int main()
{
   int a[10] = {1,2,3,4,5,6,7,8,9,10};
   
    printf("result %d \n", binsearch(a,  11, 0, 10));
    printf("result %d \n", binsearch(a,  10, 0, 10));
    printf("result %d \n", binsearch(a,  4, 0, 10));
    
    getch();
return 0;
}
