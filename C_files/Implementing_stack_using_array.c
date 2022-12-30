#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int top;
    int *arr;
} struck;

struck *intialised(int n);
int isFull(struck *element);
int isEmpty(struck *element);
void push(struck *element, int n);
void total_print(struck *element);
int pop(struck *element);
int peek(struck *element, int i);
int struckTop(struck *element);
int struckBottom(struck *element);
void del(struck *element);

int main()
{
    int n;
    printf("Enter the size of element in struck :: ");
    scanf("%d", &n);
    struck *element = intialised(n);

    printf("Enter the no of element for push operatoin :: ");
    scanf("%d", &n);
    push(element, n);

    printf("Bottom most element in stuck is %d\n",struckBottom(element));
    printf("Top most element of struck is %d\n",struckTop(element));
    printf("Print total element in struck other operation ::\n");

    total_print(element);
    printf("Enter the no for pulled the element :: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        printf("one element pulled :: %d\n", pop(element));

    printf("Print total element in struck after pulled ::\n");
    for (int i = 1; i < (element->top + 2); ++i)
        printf("%d\n", peek(element, i));

    del(element);

    return 0;
}

struck *intialised(int n)
{
    struck *element;
    element = (struck *)malloc(sizeof(struck));
    element->size = n;
    element->arr = (int *)malloc(n * sizeof(int));
    element->top = -1;
    return element;
}

void push(struck *element, int n)
{
    printf("Enter the %d elements ::\n", n);
    for (int i = 0; i < n; ++i)
    {
        if (isFull(element))
        {
            printf("struct is full. so no more element can enter\n\t");
            return;
        }
        ++(element->top);
        printf("\t%d) ", (i + 1));
        scanf("%d", &(element->arr[element->top]));
    }
    return;
}

void total_print(struck *element)
{
    printf("Element in struck ::\n");
    for (int i = 0; i <= (element->top); ++i)
        printf("\t%d\n", element->arr[i]);
    return;
}

int pop(struck *element)
{
    if (isEmpty(element))
    {
        printf("Struck is empty\n");
        free(element->arr);
        exit(1);
    }
    --(element->top);
    return element->arr[element->top + 1];
}

int peek(struck *element, int i)
{
    int index = (element->top + 1 - i);
    if ((index < 0) || (index >= element->size))
    {
        printf("index is invalid\n");
        exit(1);
    }
    else if (index > element->top)
    {
        printf("Empty that index of stuck\n");
        return 0;
    }
    else
    {
        return element->arr[index];
    }
}

int struckTop(struck *element)
{
    return element->arr[element->top];
}

int struckBottom(struck *element)
{
    return element->arr[0];
}

int isEmpty(struck *element)
{
    if (element->top == (-1))
        return 1;
    else
        return 0;
}

int isFull(struck *element)
{
    if (element->size == (element->top + 1))
        return 1;
    else
        return 0;
}

void del(struck *element)
{
    free(element->arr);
    free(element);
    return ;
}
