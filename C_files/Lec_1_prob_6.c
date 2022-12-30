#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int a[4] , i ;
    for(i=0;i<4;++i)
    {
        printf("Enter the %dth number : ",(i+1));
        scanf("%d",&a[i]);
    }
    for(i=0;i<4;++i)
    {
        printf("        %d\n",a[i]);
    }
    return 0;
 }