#include <stdio.h>
#include <stdlib.h>

typedef struct node //@ Creat a user define link list.
{
    int number;
    struct node *next;
} node;

int main()
{
    //~ declear the variable.
    register node *head, *p = NULL, *q;
    int n;

    printf("Enter the non Zero number ::\n");
    while (1) //* Creat a unknow number of list of node variable.
    {
        scanf("%d", &n);
        if (!n)
            break;
        q = p;
        p = (node *)malloc(sizeof(node));
        p->number = n;
        p->next = NULL;
        if (q == NULL)
            head = p;
        else
            q->next = p;
    }

    printf("\nPrint the link list ::\n"); //# print the member of variable.
    for (p = head, n = 0; p; p = p->next, ++n)
        printf("%d\n", p->number);
    printf("print is finished.\n");
    printf("No of node :: %d\n", n);

    for (q = head; p = q; free(p)) //* free the heap variable.
        q = p->next;

    return 0;
}