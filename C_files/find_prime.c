#include <stdio.h>
#include <stdlib.h>

typedef struct numset
{
    long int prime[1000];
    struct numset *next ;
}set;

int main(int argc ,char *argv[])
 {
    set *head , *p ,*q;
    register long int  n ,  last_num , *arr ,no_prime , i ;
    register int m  ;
    int j ;

    head = (set *)malloc(sizeof(set));
    head->next=NULL;
    p = head;

    printf("Enter the final degree of number for finding prime number : ");
    scanf("%d",&j);

    for(m=1,last_num=1;m<j;++m) 
        last_num*=10;

    for(n=5,no_prime=1,p->prime[0]=3,m=0; n<last_num; n+=2)
    {     
         for(i=0,j=1,q=head,arr = head->prime; (arr[i]*arr[i]) <= n; ++i)   // Find the prime number.
         {  
            if((n%(arr[i]))==0) 
               {
                j=0;
                break;
               }
            if(i==999) 
            {
              q=q->next;
              arr = q->prime ;
              i= (-1);
            }
         }

         if(j)                 // Store the find prime number.
         {
            ++no_prime;
            ++m ;
            if(m==1000)
            {
                p->next = (set *)malloc(sizeof(set));
                 p = p->next;
                 p->next=NULL;
                 m=0;
            }
            p->prime[m] = n;
         }
    }
    
          FILE *fptw ;                   // Store the prime number in file.
          fptw = fopen(argv[1],"a");
           if(fptw==NULL)
           {
            printf("Error! for open the %s file.\n",argv[1]);
            exit (-1);
           }

         fprintf(fptw,"No of Prime number in between 0 to %ld is %d.\n",last_num,no_prime+1);
         fprintf(fptw,"Below the following prime number\n 2 \t\tDifferent between previous prime\n");
         for(i=0,m=0,q=head,n=2;i<no_prime;++i,++m)
         {
            if(m==1000)
            {
                p = q->next;
                free(q);
                q = p;
                arr = q->prime ;
                m=0;
            }
            fprintf(fptw," %ld ,\t\t%ld\n",arr[m],arr[m]-n);
            n = arr[m];
         }
         free(q);
         fprintf(fptw,"number is finished.\n");
         fclose(fptw);
         printf("\ncomputation is finished.\n");

    return 0;
 }