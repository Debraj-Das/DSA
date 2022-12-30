#include <stdio.h>
#include <stdlib.h>

typedef char *string;

typedef struct link_list
{
    char data;
    struct link_list *next;
} node;

typedef struct
{
    node *top;
    int size;
} struck;

char *getstring(char end);
struck *intiallised();
int is_empty(struck *element);
void push(struck *element, char n);
int pop(struck *element, char n);
char struck_top(struck *element);
void del(struck *element);
int check_paranthesis(string exp);

int main()
{
        // get a expression
    string expression;
    printf("Enter the expression ::\n\t");
    expression = getstring('\n');
            // check experssion valid or not
    if (check_paranthesis(expression))
        printf("prethesis of expression is right\n");
    else
        printf("parenthesis of expression is not right\n");
        // free the heap allocated space for expression
    free(expression);
    return 0;
}

char *getstring(char end)
{
    typedef struct parts
    {
        char str[1000];
        struct parts *next;
    } part;

    part *head = (part *)malloc(sizeof(part));
    register part *p, *q;
    register char ch;
    register int i, n = 0;

    p = head;
    while (1)
    {
        for (i = 0; i < 1000; ++i)
        {
            ch = getchar();
            p->str[i] = ch;
            if (ch == end)
                goto jump;
        }
        q = p;
        p = (part *)malloc(sizeof(part));
        q->next = p;
        ++n;
    }
jump:

    register char *string = (char *)malloc((n * 1000 + i + 1) * sizeof(char));
    n = 0;
    p = head;
    while (1)
    {
        for (i = 0; i < 1000; ++i)
        {
            ch = p->str[i];
            if (ch == end)
            {
                string[1000 * n + i] = '\0';
                goto sejump;
            }
            string[1000 * n + i] = ch;
        }
        q = p;
        p = p->next;
        free(q);
        ++n;
    }
sejump:
    free(p);

    return string;
}

struck *intiallised()
{
    struck *element = (struck *)malloc(sizeof(struck));
    element->top = NULL;
    element->size = 0;
    return element;
}

int is_empty(struck *element)
{
    if (element->size > 0)
        return 0;
    else
        return 1;
}

void push(struck *element, char n)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Struck is Full,so %d element not add\n", n);
        exit(1);
    }
    p->data = n;
    p->next = element->top;
    element->top = p;
    element->size++;
    return;
}

int pop(struck *element, char n)
{
    if (n != struck_top(element))
        return 0;
    else
    {
        node *p = element->top;
        element->top = p->next;
        free(p);
        --element->size;
        return 1;
    }
}

char struck_top(struck *element)
{
    if (is_empty(element))
    {
        printf("Struck is empty\n");
        return 0;
    }
    else
        return (element->top)->data;
}

void del(struck *element)
{
    node *p;
    while (element->size)
    {
        p = element->top;
        element->top = p->next;
        free(p);
        --element->size;
    }
    free(element);
    return;
}

int check_paranthesis(string exp)
{
    struck *element = intiallised();
    for (int i = 0, bool; exp[i]; ++i)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(element, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (exp[i] == ')')
                bool = pop(element, '(');
            else if (exp[i] == '}')
                bool = pop(element, '{');
            else
                bool = pop(element, '[');

            if (bool == 0)
            {
                del(element);
                return 0;
            }
        }
    }
    if (is_empty(element))
    {
        del(element);
        return 1;
    }
    else
    {
        del(element);
        return 0;
    }
}
