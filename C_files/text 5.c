/*Name-Debraj Das
Roll no-21CH30010
text to show printers work */
#include <stdio.h>

int main()
{
    char *p;
    int i,h;
    for(i=0; i<100; ++i )
    {
        p=100000+i;
        h=(int)*p;
        printf(" %3d",h);
        if((i+1)%25==0) printf("\n");
    }
    return 0;
}
