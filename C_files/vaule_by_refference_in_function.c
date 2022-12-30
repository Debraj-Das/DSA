#include <stdio.h>
#include <stdlib.h>

void address(int i)
{
    printf("Address of i in function :: %p\n",&i);
    return ;
}

int main()
{    
    int i ;
    printf("Address of i variable :: %p\n",&i);
    address(i);
    return 0;
}