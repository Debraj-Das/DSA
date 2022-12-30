//name-Debraj Das
//Roll no-2130010

#include <stdio.h>
#include <stdlib.h>

typedef struct string_node {
            int n;
            struct string_node *next ;
} string_node;

int main()
{
   string_node *head, *p;
   long long int n;
   scanf("%lld",&n);
   head = (string_node *)malloc(sizeof(string_node));
   head->n=n;
   head->next=NULL;
   n=1;
   while(1)
   {
       if(head->n==1){
        while(head!=NULL)
        {
            n=n*head->n;
            p=head;
            head =head->next;
            free(p);
        }
        break ;
       }
       else {
        p=head;
        head=(string_node *)malloc(sizeof(string_node));
        head->n=p->n -1;
         head->next=p;
       }
   }
   printf("%lld",n);

    return 0;
}
