#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *list, n;
    register int i;
    printf("Enter size of array :: ");
    scanf("%d", &n);
    list = (int *)malloc(n * (sizeof(int)));
    for (i = 0; i < n; ++i)
        list[i] = (i * 4 + 1);
    printf("print the list ::\n");
    for (i = 0; i < n; ++i)
        printf("%d\n", list[i]);

    //# Time passed.
    //* now we want resized the list of array.

    int add;
    printf("How much new number you want to add :: ");
    scanf("%d", &add);
    printf("Address of the list :: %p\n",list);
     //~ realloc resize the array and copy the old array.
    list = (int *)realloc(list,(n + add) * sizeof(int));
    printf("Address of list after the realloc :: %p\n",list);
    
    printf("Enter the extre numbers :: \n");
    for (i = n; i < (n + add); i++)
    {
        printf("\t");
        scanf("%d", &list[i]);
    }
    printf("print the list after added some member ::\n");
    for (i = 0; i < (n + add); ++i)
        printf("%d\n", list[i]);

    free(list);
    return 0;
}