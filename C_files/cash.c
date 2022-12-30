#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cash, num = 0;
    do
    {
        printf("Enter the cash : ");
        scanf("%d", &cash);
    } while (cash < 0);
    while (cash > 0)
    {
        if (cash >= 25)
        {
            num += cash / 25;
            cash %= 25;
        }
        else if (cash >= 10)
        {
            num += cash / 10;
            cash %= 10;
        }
        else if (cash >= 5)
        {
            num += cash / 5;
            cash %= 5;
        }
        else
        {
            num += cash;
            cash = 0;
        }
    }
    printf("Number the coin: %d.\n", num);
    return 0;
}