#include <stdio.h>

int sum_of_the_divisor(register int num)
{
    register int new_num = 1;
    for (register int i = 2, j = (num / i); i <= j; ++i, j = (num / i))
    {
        if (num % i == 0)
        {
            new_num += (i + j);
        }
    }
    return new_num ;
}

int main()
{
    int num1 , num2 ;
    printf("Enter two numbers for check Amicable Number :: ");
    scanf("%d%d", &num1,&num2);
    // calculated ration of number 
    int new_num1 = sum_of_the_divisor(num1);
    int new_num2 = sum_of_the_divisor(num2);
    // check new_num is equal to num or not.
    if ((new_num1==num2)&&(new_num2==num1))
        printf("%d and %d are Amicable numbers\n", num1,num2);
    else
        printf("%d and %d are not Amicable pair numbers\n", num1,num2);
    return 0;
}