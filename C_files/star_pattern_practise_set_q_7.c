#include <stdio.h>
#include <stdlib.h>


int main()
{    
    int n ;
    printf("Enter the number of row :: ");
    scanf("%d",&n);
    n *=2 ;
    for(register int i = 1 , j; i < n ; i+=2)
    {
       for(j = 0 ; j<i;++j)
           printf("* ");
        printf("\n");
    }
    printf("\n");
    return 0;
}