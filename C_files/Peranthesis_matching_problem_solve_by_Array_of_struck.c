#include <stdio.h>
#include <stdlib.h>

typedef char *string;
typedef struct
{
    int size;
    int top;
    int *arr;
} struck;

char *getstring();
struck *intialised(string exp);
int isEmpty(struck *element);
void push(struck *element, char ch);
int pop(struck *element, char ch);
int struckTop(struck *element);
void del(struck *element);
int check_Paranthesis(string exp);

int main()
{
    // get a expression
    string expression;
    printf("Enter the expression ::\n\t");
    expression = getstring();

    // check experssion valid or not
    if (check_Paranthesis(expression))
        printf("Prethesis of expression is right\n");
    else
        printf("Parenthesis of expression is not right\n");

    // free the heap allocated space for expression
    free(expression);
    return 0;
}

char *getstring()
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
            if (ch == '\n')
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
            if (ch == '\n')
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

struck *intialised(string exp)
{
    int n = 0;
    for (int i = 0; exp[i]; ++i)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            ++n;
    }
    struck *element;
    element = (struck *)malloc(sizeof(struck));
    element->size = n;
    element->arr = (int *)malloc(n * sizeof(int));
    element->top = -1;
    return element;
}

void push(struck *element, char ch)
{
    ++(element->top);
    element->arr[element->top] = ch;
    return;
}

int pop(struck *element, char ch)
{
    if (ch == struckTop(element))
    {
        --(element->top);
        return 1;
    }
    else
        return 0;
}

int struckTop(struck *element)
{
    if (isEmpty(element))
        return 0;
    else
        return element->arr[element->top];
}

int isEmpty(struck *element)
{
    if (element->top == (-1))
        return 1;
    else
        return 0;
}

void del(struck *element)
{
    free(element->arr);
    free(element);
    return;
}

int check_Paranthesis(string exp)
{
    struck *element = intialised(exp);
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
    if (isEmpty(element))
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
