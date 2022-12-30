#include <stdio.h>
#include <stdlib.h>


int main()
{
    double lenth , width ;
    printf("Enter the lenth of rectangle :: ");
    scanf("%lf",&lenth);
    printf("Enter the width of rentangle :: ");
    scanf("%lf",&width);
    printf("\nThe area of rectangle is %0.2lf\n\n",lenth*width);
    
    return 0;
}