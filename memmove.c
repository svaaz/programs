#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void *mymemmove(void *dest, const void *src, size_t count);
int main(int argc, char* argv[])
{
        char *p1, *p2;
        char *p3, *p4;
        int size;
        printf("\n--------------------------------\n");
        /* ----------------------------------------
         *
         * CASE 1 : From (SRC) < To (DEST)
         *
         * +--+---------------------+--+
         * | | | |
         * +--+---------------------+--+
         * ^ ^
         * | |
         * From To
         *
         * --------------------------------------- */
        p1 = (char *) malloc(12);
        memset(p1,12,'\0');
        size=10;
        strcpy(p1,"ABCDEFGHI");
        p2 = p1 + 2;
        printf("\n--------------------------------\n");
        printf("\nFrom (before) = [%s]",p1);
        printf("\nTo (before) = [%s]",p2);
        mymemmove(p2,p1,size);
        printf("\n\nFrom (after) = [%s]",p1);
        printf("\nTo (after) = [%s]",p2);
        printf("\n--------------------------------\n");
        /* ----------------------------------------
         *
         * CASE 2 : From (SRC) > To (DEST)
         *
         * +--+---------------------+--+
         * | | | |
         * +--+---------------------+--+
         * ^ ^
         * | |
         * To From
         *
         * --------------------------------------- */
        p3 = (char *) malloc(12);
        memset(p3,12,'\0');
        p4 = p3 + 2;
        strcpy(p4, "ABCDEFGHI");
        printf("\nFrom (before) = [%s]",p4);
        printf("\nTo (before) = [%s]",p3);
        mymemmove(p3, p4, size);
        printf("\n\nFrom (after) = [%s]",p4);
        printf("\nTo (after) = [%s]",p3);
        printf("\n--------------------------------\n");
        /* ----------------------------------------
         *
         * CASE 3 : No overlap
         *
         * --------------------------------------- */
        p1 = (char *) malloc(30);
        memset(p1,30,'\0');
        size=10;
        strcpy(p1,"ABCDEFGHI");
        p2 = p1 + 15;
        printf("\n--------------------------------\n");
        printf("\nFrom (before) = [%s]",p1);
        printf("\nTo (before) = [%s]",p2);
        mymemmove(p2,p1,size);
        printf("\n\nFrom (after) = [%s]",p1);
        printf("\nTo (after) = [%s]",p2);
        printf("\n--------------------------------\n");
        printf("\n\n");
        return 0;
}

void *mymemmove1(void *dest, const void *src, size_t n)
{
        char *cdest;
        char *csrc;
        cdest = (char *)dest;
        csrc = (char *)src;

        if(!dest && !src)
                return(0);
        if (dest <= src)
        {
                while(n--)
                {
                        *cdest++ = *csrc++;
                }
        }
        else if (dest > src)
        {
                cdest += n-1;
                csrc += n-1;
                while(n--)
                {
                        *cdest-- = *csrc--; //post decrement
                }
        }
        return (dest);
}

typedef unsigned char uint8_t;

typedef unsigned int uint32_t;

void *mymemmove(void *dst, const void *src, size_t len){
    uint8_t *dp = (uint8_t *)dst;
    const uint8_t *sp = (const uint8_t *)src;

    if(dp > sp){
        sp += len;
        dp += len;
        while(len--){
            *--dp = *--sp; //pre decrement
        }
    }else{
        while(len--){
            *dp++ = *sp++;
        }
    }

    return dst;
}
