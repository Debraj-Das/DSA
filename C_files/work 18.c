//Name:Debraj Das
//Roll no-21CH30010
//expression pdf question 4.

#include <stdio.h>
#include <math.h>

int main()
{
    double P,I,N;
    printf("Respectably principal amount,Interest rate,number of year are ");
    scanf("%lf%lf%lf",&P,&I,&N);
    printf("compound interest (compount annually) is %.2lf earnd by P after N years.",P*(pow(1+I/100,N)));
    return 0;
}
