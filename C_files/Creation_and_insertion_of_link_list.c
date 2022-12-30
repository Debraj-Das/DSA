#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    // Creating of link list in manual method
    node *head, *second, *third;
    // Allocate memory for nodes in the linked list
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    // Link first and second nodes
    head->data = 2;
    head->next = second;
    // Link second and third nodes
    second->data = 3;
    second->next = third;
    // Link third node vaule
    third->data = 21;
    third->next = NULL;
    // traversal in link list
    printf("Data in link list ::\n");
    for (node *p = head; p; p = p->next)
        printf("%d\n", p->data);
    // free the link list
    for (node *p = head, *q; p; free(q))
    {
        q = p;
        p = q->next;
    }

    return 0;
}