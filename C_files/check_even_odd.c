#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n ;
    printf("Enter a number :: ");
    scanf("%d",&n);
    if(n%2 == 0)
       printf("number is even.\n");
    else 
        printf("number is odd\n");
    
    return 0;
}