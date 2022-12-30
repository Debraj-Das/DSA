#include <stdio.h>
#include <stdlib.h>

int main()
 {
    long double part , expotential  ;
    double point ;
    int i;
    printf("Enter the vaule of x of exp(x) :");
    scanf("%lf",&point);
    if(point<150)
    {
    for(i=1,part=point,expotential=1;part>(1e-15);++i,part*=(point/i))
       expotential+=part;
       if(expotential<(1e4))
       printf("vaule of exp(%lf) is %0.12lf.\n",point,(double)expotential);
       else
       {
        for(i=0;expotential>10;++i)
           expotential/=10;
           printf("vaule of exp(%lf) is %0.12lf*EXP(%d).\n",point,(double)expotential,i);
       }
    }
    else
    {    
        int exp ;
        long double fraction ;
        part=(0.4342944819033);
        part*=point;
        exp=part;
        fraction = (part-exp);
        fraction*=(2.302585092994);
        for(i=1,part=fraction,expotential=1;part>(1e-16);++i,part*=(fraction/i))
       expotential+=part;
       printf("vaule of exp(%lf) is %0.9lf*EXP(%d).\n",point,(double)expotential,exp);
    }
  return 0;
 }