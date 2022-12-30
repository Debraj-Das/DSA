//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>

typedef struct link{
        int n;
        struct link *next;
} lin;

int main()
{
    lin *p, *head,*q;
    head=NULL;
            while(1){
        if(head==NULL){
            head =(lin *)malloc(sizeof(lin ));
            printf("Enter the number : ");
            scanf("%d",&(head->n)) ;
            head->next=NULL;
            q=head;
            if(q->n==0)  break ;
        }
        else {
                p =(lin *)malloc(sizeof(lin ));
        printf("Enter the next number : ");
            scanf("%d",&(p->n)) ;
            p->next=NULL;
            if(p->n==0)  break ;
            q->next=p;
            q=p;
        }   }
        p=head;
        printf("\nDisplay the address and store number : \n\t\t");
        while(p!=NULL) {
            printf("%p %d\n\t\t",p,p->n);
            p=p->next;
        }
        p=head;
          while(p!=NULL) {
                q=p;
                 p=p->next;
            free(q);

        }
        printf("\nFinish the process.\n");
    return 0;
}
