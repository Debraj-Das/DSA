#include <stdio.h>
#include <stdlib.h>

typedef long long int point;

int main()
 {
     point **p;
     int deminsion;
     printf("Enter the deminsion of 2D dynamic array : ");
     scanf("%d",&deminsion);
     p=(point **)malloc(deminsion*sizeof(point *));
     for(int i=0;i<deminsion;++i)
     {
         p[i]=(point *)malloc(10000*sizeof(point ));
     }
     printf("For stay dynamic stores gives some input : ");
     scanf("%d",&deminsion);
     free(p);
    return 0;
 }