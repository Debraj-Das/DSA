/*Name-Debraj Das
Roll No-21CH30010
      Bubble sort
 */

#include <stdio.h>

int main()
{
    int i, j, data[100], n,t;

    scanf("%d", &n);
    for (i = 0; i < n-1; i++)
    {
        scanf("%d", &data[i]) ;
    }
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (data[j] > data[j+1])
            {
                t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
            }
        }
    }
    return 0;
}
