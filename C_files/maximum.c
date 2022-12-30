#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int max , tem , no_num ;
    printf("Enter the no of number : ");
    scanf("%d",&no_num);
    printf("Enter the number :\nremaining %d\t",no_num);
    scanf("%d",&max);
    while(--no_num)
    {
        printf("remaining %d.\t",no_num);
        scanf("%d",&tem);
        if(tem>max)  max = tem ;
    }
    printf("\nMaximum number = %d.\n",max);
    return 0;
 }