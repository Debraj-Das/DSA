#include <stdio.h>
#include <stdlib.h>


int main()
{
    int three_dimention_array[3][3][3] ;
    for(register int i =0 , j , k ; i<3 ; ++i)
       {
        for(j=0;j<3;++j)
        {
            for(k=0;k<3;++k)
                printf("%p ",&three_dimention_array[i][j][k]);
            printf("\n");
        }
        printf("\n");
       }
    
    return 0;
}