#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} double_node;

void traversal_fort_and_back(double_node *head );
void free_double_link_list(double_node *head);

int main()
{
    double_node *head = NULL, *p = NULL, *q = NULL;
    int n;
    printf("Enter the number of element :: ");
    scanf("%d", &n);
    printf("Enter the data :: \n");
    for (int i = 0; i < n; ++i)
    {
        p = (double_node *)malloc(sizeof(double_node));
        scanf("%d", &(p->data));
        p->prev = q;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
        q->next = p ;
        q = p ;
    }

    traversal_fort_and_back(head);
    free_double_link_list(head);

    return 0;
}

void traversal_fort_and_back(double_node *head )
{
    double_node *p = head , *q ;
    printf("\nPrint out fornt the list ::\n");
    while (p)
    {
        printf("%d\n",p->data);
        q = p ;
        p = p->next ;
    }
    printf("\nPrint out back of the list ::\n");
    p = q ;
    while (p)
    {
        printf("%d\n",p->data);
        q = p ;
        p = p->prev ;
    }
    return ;
}

void free_double_link_list(double_node *head)
{
    double_node *p = head , *q ;
    while (p)
    {
        q = p ;
        p = p->next ;
        free(q);
    }
    return ;   
}
