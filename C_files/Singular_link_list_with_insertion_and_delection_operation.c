#include <stdio.h>
#include <stdlib.h>

typedef struct node // Define the node
{
    int data;          // this place as you want you enter element
    struct node *next; // pointer for next element in link list
} node;
        // protype of function
void display(node *head);
void free_node(node *head);
node *insertion_at_first(node *head, int element);
node *insertion_at_end(node *head, int element);
node *insertion_at_between(node *head, int index, int element);
int insertion_after_Node(node *head, node *prenode, int element);
node *delet_at_first_node(node *head);
node *delet_in_between(node *head, int index);
node *delet_at_end(node *head);
node *delet_given_vaule(node *head, int value);

int main()
{
    // Decleartion of node pointer variable
    node *head = NULL;
    int val;
    // Allocate memory for nodes in the linked list
    for (int i = 0; i < 3; ++i)
    {
        printf("%d) Enter the element :: ", (i + 1));
        scanf("%d", &val);
        head = insertion_at_end(head, val);
    }
    // display the node element.
    printf("Data in link list ::\n");
    display(head);
    // isertion_at_first
    head = insertion_at_first(head, 56);
    printf("Data in link list after insertion at 1st 56 ::\n");
    display(head);
    // insertion at between
    int index;
    printf("Enter the element and index :: ");
    scanf("%d%d", &val, &index);
    head = insertion_at_between(head, index, val);
    display(head);
    // insertion after a node
    if (insertion_after_Node(head, head->next, 1341))
    {
        printf("Data in list after insertion 1341 after 2 node ::\n");
        display(head);
    }

    // delete the first node
    head = delet_at_first_node(head);
    printf("Link list after deletion first element ::\n");
    display(head);
    // delete the last node
    head = delet_at_end(head);
    printf("Link list after deletion last node\n");
    display(head);
    // for do some work with code
    for (int i = 0; i < 3; ++i)
    {
        printf("%d) Enter the element :: ", (i + 1));
        scanf("%d", &val);
        head = insertion_at_end(head, val);
    }
    printf("The element of list ::\n");
    display(head);
    printf("Enter a value of delet for list :: ");
    scanf("%d", &val);
    // delete the given value form the list
    head = delet_given_vaule(head, val);
    printf("List element after deleting %d element form list::\n", val);
    display(head);
    // deleting element a given index form list
    printf("Enter the index for which you want to delete:: ");
    scanf("%d", &val);
    head = delet_in_between(head, val);
    printf("List element after delete %dth element::\n", val);
    display(head);

    free_node(head);

    return 0;
}

void display(node *head)
{
    // traversal in link list
    for (node *p = head; p; p = p->next)
        printf("\t%d\n", p->data);
    printf("\n");
    return;
}

void free_node(node *head)
{
    // free the link list
    for (node *p = head, *q; p; free(q))
    {
        q = p;
        p = q->next;
    }
    return;
}

node *insertion_at_first(node *head, int element)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = element;
    p->next = head;
    return p; // replace head by new note
}

node *insertion_at_end(node *head, int element)
{
    // try to find out last element
    if (head)
    {
        node *p;
        for (p = head; p->next; p = p->next)
            ;
        // set new element at the last element
        p->next = (node *)malloc(sizeof(node));
        p = p->next;
        p->data = element;
        p->next = NULL;
        return head;
    }
    else
    {
        head = (node *)malloc(sizeof(node));
        head->data = element;
        head->next = NULL;
        return head;
    }
}

node *insertion_at_between(node *head, int index, int element)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = element;
        head->next = NULL;
    }
    else
    {
        if (index == 1)
        {
            node *p = (node *)malloc(sizeof(node));
            p->data = element;
            p->next = head;
            head = p;
        }
        else
        {
            node *p = head, *q;
            for (int i = 1; i < index; ++i)
            {
                q = p;
                p = p->next;
                if (p == NULL)
                    break;
            }
            if (p == NULL)
            {
                p = (node *)malloc(sizeof(node));
                p->data = element;
                p->next = NULL;
                q->next = p;
            }
            else
            {
                node *new = (node *)malloc(sizeof(node));
                new->data = element;
                new->next = p;
                q->next = new;
            }
        }
    }
    return head;
}

int insertion_after_Node(node *head, node *prenode, int element)
{
    int bool = 0;
    for (node *p = head; p; p = p->next)
    {
        if (p == prenode)
        {
            bool = 1;
            break;
        }
    }
    if (bool)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = element;
        new->next = prenode->next;
        prenode->next = new;
        return 1;
    }
    else
        printf("Node not present in list\n");
    return 0;
}

node *delet_at_first_node(node *head)
{
    node *p = head;
    head = head->next;
    free(p);
    return head;
}

node *delet_in_between(node *head, int index)
{
    if (head == NULL)
        printf("List is empty\n");
    else
    {
        if (index == 0)
        {
            node *p = head;
            head = head->next;
            free(p);
        }
        else
        {
            node *p = head, *q;
            for (int i = 1; i < index; ++i)
            {
                q = p;
                p = p->next;
                if (p == NULL)
                    break;
            }
            if (p == NULL)
                printf("List size smaller than given index\n");
            else
            {
                q->next = p->next;
                free(p);
            }
        }
    }
    return head;
}

node *delet_at_end(node *head)
{
    // try to find out last element
    if (head)
    {
        node *p, *q = NULL;
        for (p = head; p->next; p = p->next)
            q = p;
        // delet the last element of link list
        if (q == NULL) // this case for one element case.
        {
            free(head);
            return NULL;
        }
        else
        {
            q->next = NULL;
            free(p);
            return head;
        }
    }
    else
    {
        printf("List is empty\n");
        return head;
    }
}

node *delet_given_vaule(node *head, int value)
{
    node *p;
    while (head->data == value)
    {
        p = head;
        head = head->next;
        free(p);
    }
    node *q, *del;
    for (p = head->next, q = head; p; p = p->next)
    {
        while ((p->data == value))
        {
            q->next = p->next;
            del = p;
            p = p->next;
            free(del);
            if (p == NULL)
                return head;
        }
        q = p;
    }
    return head;
}
