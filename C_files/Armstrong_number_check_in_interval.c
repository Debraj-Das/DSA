#include <stdio.h>

int power(register int a , register int b)
{
    register int val , i ;
    for(val = 1 , i = 0 ; i<b ; ++i)
        val*=a;
    return val ;
}

int check_armstrong_number(register long long int number)
{
    register long long int tum, new_number;
    register int no_of_digit;
    for (no_of_digit = 0, tum = number; tum; ++no_of_digit)
        tum /= 10;
    // find new number
    for (new_number = 0, tum = number; tum; tum /= 10)
        new_number += power((tum % 10), no_of_digit);
    if (new_number == number)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *fptw ;
    fptw = fopen("Armstrong.txt","w");
    long long int lower , upper ;
    printf("Enter a lower number :: ");
    scanf("%lld", &lower);
    printf("Enter a upper number :: ");
    scanf("%lld", &upper);
    fprintf(fptw,"Armstrong numbers between %lld and %lld are ::\n",lower,upper);
    for(register long long int i = lower;i<=upper;++i)
    {
        if(check_armstrong_number(i))
            fprintf(fptw,"%lld\n",i);
    }
    return 0;
}
