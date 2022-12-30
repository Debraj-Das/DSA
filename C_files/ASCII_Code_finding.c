#include <stdio.h>
#include <stdlib.h>

int main()
 {
   char character ;
   printf("If you want to exit form process enter a\n");
    do 
    {   
        printf("Enter character for see ASCII Code : ");
        scanf("%c",&character);
        printf("\t ASCII Code = %d\n",character);
        getchar() ;
    }
    while(character!='a');
    return 0;
 }