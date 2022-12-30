// This file's executable file name mc.exe.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
 {
    FILE *fptc , *fptr ;

    if(argc==1) 
    {
        printf("You are not give any input. so, nothing chance.\n");
        exit(1);
    }
    else if((fptc=fopen(argv[2],"r"))!=NULL)
    {
        printf("%s file is present in this dir previously.\n",argv[1]);
        fclose(fptc);
        exit(1);
    }

    else 
      {  
        fclose(fptc);
        fptr = fopen(argv[1],"r");
        if (fptr == NULL)
    {
        printf("Error! for create the %s file.\n",argv[2]);
        exit(1);
    }
        fptc = fopen(argv[2],"w");
        if (fptc == NULL)
    {    
        fclose(fptr);
        printf("Error! for create the %s file.\n",argv[2]);
        exit(1);
    }
        char ch ;
        while(fscanf(fptr,"%c",&ch)!=EOF)    fprintf(fptc,"%c",ch);
        fclose(fptr);
        fclose(fptc);
        printf("%s file is correctly created and copy form %s.\n",argv[2],argv[1]);
      }
      
    return 0;
 }