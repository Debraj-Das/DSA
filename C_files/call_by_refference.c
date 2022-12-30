#include <stdio.h>
#include <stdlib.h>

void func(int *n)  //* call by refference.
{
    (*n)*=10 ;
    printf("Later Enter number is %d\n",*n);
    return ;
}

int main()
{
    int n ;
    printf("Enter a number :: ");
    scanf("%d",&n);
    printf("Enter number is %d\n",n);
    func(&n);
    
    return 0;
}