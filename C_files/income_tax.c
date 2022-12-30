#include <stdio.h>
#include <stdlib.h>

int main()
{
    double income, tax;
    printf("Enter the income :: ");
    scanf("%lf", &income);
    if (income >= 1000000)
        tax = (income * 0.3);
    else if (income >= 500000)
        tax = (income * 0.2);
    else if (income >= 250000)
        tax = (income * 0.05);
    else
        tax = 0;
    printf("your tax as your income is %0.2lf.\n\n", tax);
    return 0;
}