// This file's executable file name cp.exe(for commend) and copy.exe(for general).

#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char *argv[])
{
    char ch ;
    FILE *fpta ,*fptr ;
    fptr = fopen(argv[1],"r");
    if (fptr == NULL)
    {
        printf("Error! for opening %s file\n",argv[1]);
        exit(1);
    }
     if((fpta = fopen(argv[2],"r"))==NULL)
     {
         fclose(fpta);
         fpta = fopen(argv[2], "w");
         ch='0';
     }
     else
     {
    printf("If only you want to overwrite the 2nd copy give input 0 if not give any number.\n");
    printf("\tEnter input : ");
    scanf("%c", &ch);
    if (ch == '0')
        fpta = fopen(argv[2], "w");
    else
        fpta = fopen(argv[2], "a");
      }
    if (fpta == NULL)
    {
        printf("Error! for create %s file\n",argv[2]);
        exit(1);
    }
  if(ch!='0')   fprintf(fpta,"\n");

    while(fscanf(fptr,"%c",&ch)!=EOF)    fprintf(fpta,"%c",ch);

    printf("copy paste is finished.\n");


    fclose(fpta);

    return 0;
}
