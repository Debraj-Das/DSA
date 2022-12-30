#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int n,i,j;
    do 
    {
        printf("Hight : ");
        scanf("%d",&n);
    }
    while(n>8&&n<1);
    for(i=0;i<n;++i)
    {
        for(j=1;j<n-i;++j) printf(" ");
        for(j=0;j<=i;++j) printf("#");
        printf(" ");
        for(j=0;j<=i;++j) printf("#");
        printf("\n");
    }
    return 0;
 }