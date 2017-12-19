#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct StringBoundedArray
{
int size;
int **arr;
}stringboundedarray;
stringboundedarray * subStringsKDist(char* inputStr, int num);
int main()
{
char *input= "awaglknagawunagwkwagl";
int num =4;
stringboundedarray * b= subStringsKDist(input, num);	
}

stringboundedarray * subStringsKDist(char* inputStr, int num)
{
		int i =0;
		int j=0;
	int n = strlen(inputStr);
    int res = 0; 
    int char_count[26] = {0};
 	char ch_str[26];
	stringboundedarray *ba = calloc( 1, sizeof(stringboundedarray));
	
	char **arr = (char**) calloc(100, sizeof(char*));

    for ( i = 0; i < 100; i++ )
    {
        arr[i] = (char*) calloc(26, sizeof(char));
    }
	
 
    for (i = 0; i < n; i++)
    {
        int unique_count = 0;
 
        memset(char_count, 0, sizeof(char_count));
 		memset(ch_str, 0, sizeof(ch_str));
 		int k =0;
           
        for (j=i; j<n; j++)
        {        
				
            if (char_count[inputStr[j] - 'a'] == 0 )
            {
   			    ch_str[k++] = inputStr[j];
			    unique_count++;
			}
            
            char_count[inputStr[j] - 'a']++;
 
            if (unique_count == num)
            {
            	res++;
            	break;
            }
        }
        char_count[k]='\0';
        if(strlen(ch_str) == num)
          strcpy(arr[res], ch_str);
        printf("%s ", arr[res]);
    }
 	ba->arr= arr;
 	ba->size =res;
    return ba;
}
