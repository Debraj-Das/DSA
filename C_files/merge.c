#include <stdio.h>
#include <stdlib.h>

void merge_sorting(int *p, int n);

int main()
{
    int *a, n;
    printf("Number of input is : ");
    scanf("%d", &n);
    a=(int *)malloc(n*sizeof(int ));
        printf("Enter the number one by one : \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    merge_sorting(a, n);
    printf("Arrangment of date by Merge sorting \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d th number %d \n", i+1, a[i]);
    }
    return 0;
}

void merge_sorting(int *p, int n)
{
    int mid = n / 2;
    if (n == 1)
        return;
    merge_sorting(p, mid);
    if (n % 2 == 1)
    {
        merge_sorting(&p[mid], mid + 1);
    }
    else
    {
        merge_sorting(&p[mid], mid);
    }
   int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
       {
            q[i] = p[i];
       }
    for (int i = 0, j = 0; i < n; ++i)
    {
        if ((q[j] < q[mid]||mid>=n) && j < n / 2)
        {
            p[i] = q[j];
            ++j;
        }
        else if (mid < n)
        {
            p[i] = q[mid];
            ++mid;
        }
    }
    free(q);
    return;
}