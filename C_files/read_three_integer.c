#include <stdio.h>
#include <stdlib.h>


int main(int agc , char *agv[])
{
    FILE *fpr = fopen(agv[1],"r")  ;
    if(fpr==NULL)
    {
        printf("File is not exit.");
        exit(1);
    }
    int a[3];
    for(register int i = 0 ; i < 3 ; ++i)
    {
        fscanf(fpr,"%d",&a[i]);
    }
    for(register int i = 0;i<3;++i)
     printf("%d\n",a[i]);
    
    return 0;
}