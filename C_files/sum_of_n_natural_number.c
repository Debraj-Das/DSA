#include <stdio.h>
#include <stdlib.h>

int sum(register int n)
{
    register int sum = 0 ;
    while(n)
        sum +=(n--);
    return sum ;
}

int main()
{
    int n ;
    printf("Enter the number :: ");
    scanf("%d",&n);
    printf("sum of %d number is %d\n\n",n,sum(n));
    
    return 0;
}