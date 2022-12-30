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
    while(n>9&&n<0);
    for(i=n;i>0;--i)
    {
        for( j=1;j<i;++j) printf(" ");
        for( j=0;j<=n-i;++j) printf("#");
        printf("\n");
    }
    printf("\n Second perimid :\n");
    for(i=1;i<=n;++i)
    {
        for(j=0;j<i;++j) printf("#");
        printf("\n");
    }
    printf("\nThird perimid :\n");
     for(i=n;i>0;--i)
    {
        for( j=1;j<i;++j) printf(".");
        for( j=0;j<=n-i;++j) printf("#");
        printf("\n");
    }   
    return 0;
 }