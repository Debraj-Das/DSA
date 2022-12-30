#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year ;
    printf("Enter the year :: ");
    scanf("%d",&year);
    if(year%4 || year%400==0)
        printf("%d year is not a leaper year.\n",year);
    else 
        printf("%d is a leaper year.\n",year);
    return 0;
}