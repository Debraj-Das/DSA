//Name:Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
   float x;
   printf("Read the principal carefully\nif number of months of deposit is:");
   scanf("%f",&x);
   if(x<=1)
    printf("thus number of months of deposit less than and equal to 1 month.so compute interest 4%.");
   else if(x>1&&x<=12)
     printf("thus number of months of deposit less than and equal to 12 month and more than 1 mouth.so compute interest 7%.");
    else if(x>12&&x<=24)
      printf("thus number of months of deposit less than and equal to 24 month and more than 12 mouth.so compute interest 8%.");
    else if(x>24&&x<=60)
       printf("thus number of months of deposit less than and equal to 60 month and more than 24 mouth.so compute interest 9%.");
    else
      printf("thus number of months of deposit more then l to 1 month.so compute interest 8%.");
    return 0;
}
