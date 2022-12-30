#include <stdio.h>
#include <stdlib.h>

long long int getsint()
{
    long long int ret ;
    printf("Enter the n : ");
    scanf("%lld",&ret);
    return ret ;
}

int main()
 {
    register long long int n  ;
    register int i ;
    register long double fraction , value = 1 ;
    n = getsint() ;
    fraction = (1+1.0/n);
    i = n%4 ;
    while (i--)
    {
        value *= fraction ;
    }
    n/=4;
    while(n)
    {
      for(i=0;i<2;++i)
       fraction*=fraction;
       i = n%4 ;
    while (i--)
    {
        value *= fraction ;
    }
    n/=4;
    }
    printf("natural exp value for %lld is %0.12lf\n",n,(double)value);
    return 0;
 }