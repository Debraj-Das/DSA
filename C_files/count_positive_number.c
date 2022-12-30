#include <stdio.h>
#include <stdlib.h>

int count(int arr[])
{
    int n, i;
    for (n = 0, i = 0; i < 10; ++i)
    {
        if (arr[i] > 0)
            ++n;
    }
    return n;
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; ++i)
    {
        printf("%d) ", (i + 1));
        scanf("%d", &arr[i]);
    }
    int n = count(arr);
    printf("positive number in array is %d\n\n", n);
    return 0;
}