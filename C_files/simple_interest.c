#include <stdio.h>
#include <stdlib.h>

int main()
 {
   double principal , no_of_year , rate_of_interest , simple_interest ;
   printf("Enter the values of principal, no of year , rate of interest(%%) respectively :\n\t");
   scanf("%lf%lf%lf",&principal,&no_of_year,&rate_of_interest);
   printf("Value of Simple interest is %lf.\n",(principal*no_of_year*rate_of_interest)/100);
   return 0;
 }