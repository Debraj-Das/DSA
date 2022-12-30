#include <stdio.h>
#include <stdlib.h>

void muti_ten(int n)
{
    n*=10 ;
    printf("vaule of n in function is %d\n",n);
    return ;
}

int main()
{
    int n ;
    printf("Enter a number :: ");
    scanf("%d",&n);
    muti_ten(n);
    printf("In general vaule of function call by vaule so n = %d.\n",n);
    
    return 0;
}