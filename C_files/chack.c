#include <stdio.h>
#include <stdlib.h>

int find(int a[], int n, int i)
{
    int j, p = 0;
    double m1, m2,lum1,lum2;
    m1 = (double)(a[i + 3] - a[i + 1]) / (a[i + 2] - a[i]);
    for (j = i + 4; j < 2*n ; j += 2)
    {
        m2 = (double)(a[j + 3] - a[j + 1]) / (a[j + 2] - a[j]);
        if (m1 != m2)
        {
            m2 = (double)(a[j + 1] - m2 * a[j] - a[i + 1] + m1 * a[i]) / (m1 - m2);
           lum1=(a[i]-m2)/(m2-a[i+2]);
           lum2=(a[j]-m2)/(m2-a[j+2]);
           if(lum1>0&&lum2>0) ++p;
        }
    }
    printf("\n%d\n",p);
    return p;
}

int main()
{
    int i, n, a[800], c = 0;
    printf("How many vertices? ");
    scanf("%d", &n);
    printf("Enter X and Y co-ordinates:\n");
    for (i = 0; i < 2 * n; i += 2)
    {
        scanf("%d%d", &a[i], &a[i + 1]);
    }
    a[n]=a[0];
    a[n+1]=a[1];
    for (i = 0; i < 2*n-2; i += 2)
    {
        c += find(a, n, i);
    }
    if (c == 0)
        printf("Polygon is a simple polygon.\n");
    else
    {
        printf("Polygon is not a simple polygon.\n");
        printf("Number of intersecting pairs of non-adjacent sides is %d\n", c);
    }
    return 0;
}
