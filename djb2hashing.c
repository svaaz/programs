#include<stdio.h>

#define TP_CARD_COUNT 5

/* This Program tests the distribution of DJB2 Hashing Algorithm, just for my satisfaction that it work ;) ;) */

//http://www.cse.yorku.ca/~oz/hash.html

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TP_CARD_COUNT+1;
}

char *randstring(int length) 
{    
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;
    int n;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for ( n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;        
    }
    else {
        printf("No memory");
        exit(1);
    }
}
int main()
{

    int i =0;
    int a[5]= {0,0,0,0,0};
    char *str=NULL;
    int hs =0;

    for(i=0;i<10000;i++)
    {
        str = randstring(5);
        hs = hash(str);
        a[hs-1]++;
        printf("\n hash for %s is %d", str, hs);
        free(str);
        str = NULL;
    }

    for(i=0;i<5;i++)
        printf("\nDistribution of %d is %d", i , a[i]);
}
