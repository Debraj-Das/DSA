#include <stdio.h>
#include <stdlib.h>

int main()
 {
    double cent , fahr ;
    printf("Enter Centigrade : ");
    scanf("%lf",&cent);
    fahr = ((9.0/5)*cent) + 32 ;
    printf("%lf C equals %lf F\n",cent,fahr);
    return 0;
 }