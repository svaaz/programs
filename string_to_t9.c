#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void conver_to_t9_digits2(char *str, unsigned int len)
{
char t9[50];
int i =0;
char buttons[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
int index =0;

for(i = 0; str[i]; i++)
{
  str[i] = tolower(str[i]);
}

for(i=0;i<len;i++)
{
    index = (unsigned int)(str[i])-97; //97 is ASCII of 'a'
    
    if(index > 25)
    {
        printf("\n Invalid input detected !!");
        break;
    }

    t9[i] = buttons[index];
}

t9[i] ='\0';

printf("Converted T9 string: %s \n\n\n",t9);


}

void conver_to_t9_digits(char *str, unsigned int len)
{

char t9[50];
int i =0;

for(i = 0; str[i]; i++)
{
  str[i] = tolower(str[i]);
}

for(i=0;i<len;i++)
{
    switch(str[i])
    {
        case 'a':
        case 'b':
        case 'c':
            t9[i] = '2';
            break;
        case 'd':
        case 'e':
        case 'f':
            t9[i] = '3';
            break;
        case 'g':
        case 'h':
        case 'i':
            t9[i] = '4';
            break;
        case 'j':
        case 'k':
        case 'l':
            t9[i] = '5';
            break;
        case 'm':
        case 'n':
        case 'o':
            t9[i] = '6';
            break;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            t9[i] = '7';
            break;
        case 't':
        case 'u':
        case 'v':
            t9[i] = '8';
            break;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            t9[i] = '9';
            break;
        default:
            printf("\n Invalid input");
    }
}

t9[i] ='\0';

printf("Converted T9 string: %s \n\n\n",t9);

}

int main()
{

char str[50];
printf("\nEnter Input:");
scanf("%s", &str);

unsigned int len = strlen(str);
conver_to_t9_digits2(str, len);

}
