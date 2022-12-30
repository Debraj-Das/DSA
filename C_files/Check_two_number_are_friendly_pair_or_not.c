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
    return new_num+num ;
}

int main()
{
    int num1 , num2 ;
    printf("Enter two number for check friend pair :: ");
    scanf("%d%d", &num1,&num2);
    // calculated ration of number 
    double ration1 = (sum_of_the_divisor(num1)/num1);
    double ration2 = (sum_of_the_divisor(num2)/num2);
    // check new_num is equal to num or not.
    if (ration1==ration2)
        printf("%d and %d are friend pair numbers\n", num1,num2);
    else
        printf("%d and %d are not friend pair numbers\n", num1,num2);
    return 0;
}