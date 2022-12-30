//Debraj Das
//Roll no-21CH30010
//find the factor of a given number.
#include <stdio.h>

int main()
{
    int n,x,fac;
    printf("Enter the number:");
    scanf("%d",&n);
    for(x=2,fac=1;x<=n;++x) fac=fac*x;
    printf("     %d!=%d.",n,fac);
    return 0;
}
