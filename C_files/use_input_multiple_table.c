#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][10], *num, n;
    printf("Enter no of multiple tabel :: ");
    scanf("%d", &n);
    num = (int *)malloc(n * sizeof(int));
    for (register int i = 0, j; i < n; ++i)
    {
        printf("multiple table of  :: ");
        scanf("%d", &num[i]);
        for (j = 0; j < 10; ++j)
        {
            arr[i][j] = (j + 1) * num[i];
            printf("%d ", arr[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
    free(num);
    return 0;
}