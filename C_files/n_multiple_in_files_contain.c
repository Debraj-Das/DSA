#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
   long long int point ;
   struct link *next ;
} list ;


int main(int argc ,char *argv[])
{
    if(argc == 1)                   //~ open file correctly.
     {
        printf("Next time Please enter file name.\n");
        exit(1);
     }
    FILE *pre_fptr , *chn_fptw ;
    pre_fptr = fopen(argv[1],"r");
    if(pre_fptr == NULL)
     {
        printf("Any reason file is not open.\n");
        exit(1);
     }

     list *head , *p , *q ;   //# Take input in variable form file.
     p = head = (list *)malloc(sizeof(list ));
     p->next = NULL ;
     while(fscanf(pre_fptr,"%lld",&(p->point)) != EOF) 
        {  
           q = p ;
           p = (list *)malloc(sizeof(list ));
           q->next = p ;
           p->next = NULL ;
        }
         fclose(pre_fptr);

      int n ;
      printf("Enter the multipul number :: ");  //* Print output in files.
      scanf("%d",&n);   
   pre_fptr = fopen(argv[1],"w");
    for(p = head ; (p->next) != NULL ; p = (p->next))
        fprintf(pre_fptr,"%lld\n",n*(p->point));
     
     for(p = head ; p != NULL ; p = q)
         {
            q = p->next ;
            free(p) ;
         }
   fclose(pre_fptr);
    printf("Work is finished.\n");

    return 0;
}