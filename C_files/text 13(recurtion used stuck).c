//name-Debraj Das
//Roll no-21CH30010
// Recursion used stuck.

#include <stdio.h>
#include <stdlib.h>

typedef struct string_node
{
    int a;
    struct string_node *next;
} string_node;

int main()
{
    string_node *head, *p;
    int n=0,x;
    printf("Enter the position of the term : ");
    scanf("%d",&x);
    head =(string_node *)malloc(sizeof(string_node ));
    head->a=x;
    head->next=NULL;
    while(head!=NULL)
    {
        if(head->a==1||head->a==2)
        {
            n+=1;
            p=head;
            head=head->next;
            free(p);
        }
        else {
            head->a-=1;
            p=head;
             head =(string_node *)malloc(sizeof(string_node ));
          head->a=p->a-1;
        head->next=p;
        }
    }
    printf("Number the Fibonacci series of position %d = %d .",x,n);

    return 0;
}
