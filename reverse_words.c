#include <stdio.h>
#include <stdlib.h>

static char * reverse(char *str)
{
 int i=0;
 int j = strlen(str) - 1;
 char temp;

   while (i < j) 
   {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
   
   return str;
}
int main(int argc, char *argv[])                                                
{
    char a[64] = "Hi how are you ? - - ";
    int i =0; int j =0 ;
    char *temp = malloc(sizeof (char)*64);
    
    for(i=strlen(a)-1;i>=0;i--)
    {
      if(a[i] == ' ')
      {
        temp[j++] = ' ';
        temp[j++] = '\0';
        printf("%s", reverse(temp));
        j=0;
      }
      else
      {
       temp[j++] = a[i]; 
      }
    }
    /* to print last word*/
    temp[j++] = a[i];
    temp[j++] = '\0';
    printf("%s \n", reverse(temp));
  
  system("PAUSE");	
  return 0;
}
