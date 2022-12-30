#include <stdio.h>
#include <stdlib.h>

int gcd_func(int a, int b);

int main()
{
    int num1, num2;
    printf("Enter two number :: ");
    scanf("%d%d", &num1, &num2);
    int gcd = gcd_func(num1, num2);
    int lcm = (num1*num2)/gcd ;
    printf("gcd = %d , lcm = %d of %d and %d\n",gcd,lcm,num1,num2);
    return 0;
}

int gcd_func(register int a, register int b)
{
    register int tum;
    if (a > b)
    {
        tum = a;
        a = b;
        b = tum;
    }
    while (a)
    {
        tum = (b % a);
        b = a;
        a = tum;
    }
    return b;
}

