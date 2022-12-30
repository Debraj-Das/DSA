#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
 {
     int n;
     printf("Enter the number which you show : ");
     scanf("%d",&n);
    for(int *pointer=&argc,i=0;i<n;++i,++pointer)
    printf("%d . %p adderess store intger %d.\n",i+1,pointer,*pointer);
    return 0;
 }