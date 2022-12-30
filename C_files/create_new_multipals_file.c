// This file's executable file name mf.exe.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
 {
    FILE *fptc ;
    if(argc==1) 
    {
        printf("You are not give any input. so, nothing chance.\n");
        exit(1);
    }
    else if((fptc=fopen(argv[1],"r"))!=NULL)
    {
        printf("%s file is present in this dir previously.\n",argv[1]);
        fclose(fptc);
        exit(1);
    }
    else 
      {  
        fclose(fptc);
        for(int i=1;i<argc;++i)
        {
        fptc = fopen(argv[i],"w");
        if (fptc == NULL)
    {
        printf("Error! for create the %s file.\n",argv[i]);
        exit(1);
    }
        fclose(fptc);
        printf("%s file is correct created.\n",argv[i]);
        }
      }
    return 0;
 }