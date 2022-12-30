#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
 {
    FILE *fptc ;
    fptc = fopen(argv[1],"r");
    if(fptc==NULL)
    {
        printf("file is not present in dir for clear it.\n");
        fclose(fptc);
    }
    else
    {
        fclose(fptc);
        fptc = fopen(argv[1],"w");
        fclose(fptc);
    }
    return 0;
 }