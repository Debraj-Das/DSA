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
    i = n%1024 ;
    while (i--)
    {
        value *= fraction ;
    }
    n/=1024;
    while(n)
    {
      for(i=0;i<10;++i)
       fraction*=fraction;
       i = n%1024 ;
    while (i--)
    {
        value *= fraction ;
    }
    n/=1024;
    }
    printf("natural exp value for %lld is %0.12lf\n",n,(double)value);
    return 0;
 }