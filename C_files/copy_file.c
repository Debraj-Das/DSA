#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    if(argc<3)
      {
        printf("Next time please enter files name.\n");
        exit(1);
      }
    FILE *org_fptr , *cp_fptw ;
    org_fptr = fopen(argv[1],"r");
    if(org_fptr == NULL)
     {
        printf("File is not present or did not open files properly.\n");
        exit(1);
     }
    cp_fptw = fopen(argv[2],"r");
    char c ;
    if(cp_fptw != NULL)
    {
        fclose(cp_fptw);
         printf("Are you want to overwrite %s file if Yes(y) other no:: ",argv[2]);
         scanf("%c",&c);
         if(c != 'y') 
            exit(0);
    }
    cp_fptw = fopen(argv[2],"w");
    while(fscanf(org_fptr,"%c",&c) != EOF)
        fprintf(cp_fptw,"%c",c);
    printf("Copy work is finished.\n");

    fclose(org_fptr);
    fclose(cp_fptw);

    return 0;
}