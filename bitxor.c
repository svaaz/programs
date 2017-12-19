#include<stdio.h>
#include<stdlib.h>
#define HOUSES (8)

typedef struct BoundedArray
{
int size;
int *arr;
}boundedarray;

boundedarray* cellCompete(int* states, int days) 
{
    int cell[10]={0};
    int oldcell[10]={0};
    int day =0;
    int house =0;
    int i =0;
    boundedarray *ba = calloc( 1, sizeof(boundedarray));
    int  *arry = calloc(HOUSES, sizeof(int));
    
    
    for(i=1;i<=HOUSES;i++)
    {
        oldcell[i] = states[i-1];
    }
    
    for(day=1;day<=days;day++)
    {
        for(house=1;house<=HOUSES;house++)
        {
            cell[house]= oldcell[house-1] ^ oldcell[house+1];
		printf("h:%d", house);
        }
        
        memcpy(oldcell, cell, sizeof(cell));
        
        printf("d:%d" ,day);
    }
    
    ba->size =8;
    memcpy(&ba->arr, cell+1, HOUSES);
    
    return ba;
    
}

int main()
{
	int t [8]={1,1,1,1,1,1,1};
	int days =10;
	cellCompete(t, days);
	
	
}
