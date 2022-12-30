#include <stdio.h>
#include <stdlib.h>


int main()
{ 
    int n  ;
    printf("Enter the no of Address :: ");
    scanf("%d",&n);
    printf("Address of n :: %p.\n",&n);
    int *p = (&n) ;
    for(register int i = 0 ; i <n ; ++i)
        printf("%d) %d\n",(i+1),*(p+i));
    printf("\n\nWork finished.\n\n");
    return 0;
}