#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[3][10] , num[] = {2 , 7 , 9};
    for(register int i = 0 ,j ; i<3 ; ++i)
    {
        printf("multiple table of %d ::\n",num[i]);
        for(j= 0 ; j<10 ;++j)
        {
            arr[i][j] = (j+1)*num[i] ;
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
        printf("\n");
    
    return 0;
}