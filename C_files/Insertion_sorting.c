#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void solve();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t z = clock();

    int t = 1;
    // scanf("%d", &t);
    while (t--)
        solve();

    printf("\nRun Time : %lf\n", ((double)(clock() - z) / CLOCKS_PER_SEC));

    return 0;
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1, j, temp; i < n; ++i)
        for (j = i; (arr[j] < arr[j - 1]) && j; j--)
        {
            // swapping the arr[j] and arr[j - 1]
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }

    return;
}

void solve()
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    insertion_sort(arr, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    free(arr);
    return;
}