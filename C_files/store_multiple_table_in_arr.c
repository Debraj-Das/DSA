#include <stdio.h>
#include <stdlib.h>


int main()
{
    int mul_arr[10];
    for(register int i = 0 ; i < 10 ; ++i)
        {
            mul_arr[i] = 5*(i+1) ;
            printf("%d of 5 multiple table member :: %d\n",(i+1),mul_arr[i]);
        }
    printf("\n");
    return 0;
}