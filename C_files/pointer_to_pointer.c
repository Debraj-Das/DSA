#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **ptr_to_ptr , *ptr , n ;
    ptr = &n ;
    ptr_to_ptr = &ptr ;     //~ pointer to pointer
    printf("Enter a number :: ");
    scanf("%d",&n);         //* instead of this line you can use scanf("%d",ptr);
    printf("number is %d %d %d\n",n,*ptr,**ptr_to_ptr);
    return 0;
}