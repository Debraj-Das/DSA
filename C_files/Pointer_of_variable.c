#include <stdio.h>
#include <stdlib.h>


int main()
{    
    int n = 9 ;
    int *p = &n ;
    printf("Address of the n variable :: %p\nAnd value of variable :: %d\n",p,*p);
    return 0;
}