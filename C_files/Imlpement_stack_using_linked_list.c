#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
    int data ;
    struct link_list *next ;
} node ;

typedef struct 
{
    node *top ;
    int size ;
} struck ;

struck *intiallised();
int is_full(node *p);
int is_empty(int n);
void push(struck *element ,int n);
int peek(struck *element, int index);
int pop(struck *element);
void total_print(struck *element);
int struck_bottom(struck *element);
int struck_top(struck *element);
void del(struck *element);

int main()
{
    struck *element = intiallised() ;

    int n ;
    printf("Enter the no of element you want to enter :: ");
    scanf("%d",&n);
    for(int i =0 , j ; i <n ; ++i)
    {
        printf("%d) ",(i+1));
        scanf("%d",&j);
        push(element , j);
    }

    printf("Total element of struck is ::\n");
    total_print(element);
    printf("Enter the no of index for peek :: ");
    scanf("%d",&n);
   printf("Data at %d index is %d\n",n,peek(element, n));

   printf("Enter number element you want to pop :: ");
   scanf("%d",&n);
   for(int i = 0 ; i < n;++i)
    printf("%d element pop is %d\n",(i+1),pop(element)); 
    
    printf("Print the total element after pop ::\n");
    total_print(element);
    printf("Element of the bottom is %d\n",struck_bottom(element));
    printf("Element of the top is %d\n",struck_top(element));

    del(element);
    
    return 0;
}

struck *intiallised()
{
    struck *element  = (struck *)malloc(sizeof(struck ));
    element->top = NULL ;
    element->size = 0 ;
    return element ;
}

int is_full(node *p)
{
    if(p==NULL)
    return 1 ;
    else 
    return 0 ;
}

int is_empty(int n)
{
    if(n > 0)
    return 0 ;
    else 
    return 1 ;
}

void push(struck *element ,int n)
{
    node *p = (node *)malloc(sizeof(node ));
    if(is_full(p))
    {
        printf("Struck is Full,so %d element not add\n",n);
        return ;
    }
    p->data = n ;
    p->next = element->top ;
    element->top = p ;
    element->size++ ;
    return ;
}

int peek(struck *element, int index)
{
    node *p = element->top ;
    for(int i = 1 ; i < index ; ++i)
        p = p->next ;
    return p->data ;
}

int pop(struck *element)
{
    if(is_empty(element->size))
    {
        printf("Struck is empty\n");
        return -1 ; // I assumsed that -1 is not data of struck.
    }
    node *p = element->top ;
    int val = p->data ;
    element->top = p->next ;
    free(p);
    --element->size ;
    return val ;
}

void total_print(struck *element)
{
    node *p = element->top ;
    for(int i = 0 ; i < element->size ;++i, p = p->next)
    printf("\t%d) %d\n",(i+1),p->data);
    return ;
}

int struck_bottom(struck *element)
{
    if(is_empty(element->size))
    {
        printf("struck is empty\n");
        return -1 ;
    }
    else
    {
    node *p = element->top ;
    for(int i = 1 ;i < element->size ; ++i)
    p = p->next ;
    return p->data ;
    }
}

int struck_top(struck *element)
{
    if(is_empty(element->size))
    {
        printf("Struck is empty\n");
        return -1 ;
    }
    else
    return (element->top)->data ;
}

void del(struck *element)
{
    node *p ;
    while(element->size)
    {
        p = element->top ;
        element->top = p->next ;
        free(p);
        --element->size ;
    }
    free(element);
    return ;
}
