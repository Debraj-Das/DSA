#include <stdio.h>
#include <stdlib.h>

void oppsited(int mul_arr[])
{
    register int i, t;
    for (i = 0; i < (9 - i); ++i)
    {
        t = mul_arr[i];
        mul_arr[i] = mul_arr[9 - i];
        mul_arr[9 - i] = t;
    }
    return;
}

int main()
{
    int mul_arr[10];
    register int i;
    for (i = 0; i < 10; ++i)
        mul_arr[i] = 5 * (i + 1);
    oppsited(mul_arr);
    for (i = 0; i < 10; ++i)
        printf("%d th element after oppisite :: %d\n", (i + 1), mul_arr[i]);
    printf("\n");
    return 0;
}