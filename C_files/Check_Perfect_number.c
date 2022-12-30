#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter a number :: ");
    scanf("%d", &num);
    // calculated new number 
    register int new_num = 1;
    for (register int i = 2, j = (num / i); i <= j; ++i, j = (num / i))
    {
        if (num % i == 0)
        {
            new_num += (i + j);
        }
    }
    // check new_num is equal to num or not.
    if (new_num == num)
        printf("%d is a perfect number\n", num);
    else
        printf("%d is not a perfect number\n", num);
    return 0;
}