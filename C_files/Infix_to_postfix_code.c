#include <stdio.h>
#include <stdlib.h>

typedef char *string;
typedef struct
{
    int top;
    char *arr;
} struck;

char *getstring();
struck *intialised(string exp);
int isEmpty(struck *element);
void push(struck *element, char ch);
char pop(struck *element);
char struckTop(struck *element);
void del(struck *element);
int checkOperator(char ch);
int pecendence(char ch);
char *Infix_to_postfix(string exp);

int main()
{
    // get a infix
    string infix;
    printf("Enter the infix ::\n\t");
    infix = getstring();

    // converted infix to postfix
    char *postfix = Infix_to_postfix(infix);
    printf("postfix of ( %s ) is ( %s )\n", infix, postfix); // print postfix

    // free the heap allocated space for infix and postfix ;
    free(infix);
    free(postfix);
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
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
            ++n;
    }
    struck *element = (struck *)malloc(sizeof(struck));
    element->arr = (char *)malloc(n * sizeof(char));
    element->top = -1;
    return element;
}

void push(struck *element, char ch)
{
    ++(element->top);
    element->arr[element->top] = ch;
    return;
}

char pop(struck *element)
{
    char ch = element->arr[element->top];
    --(element->top);
    return ch;
}

char struckTop(struck *element)
{
    if (isEmpty(element))
        return '@';
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

int checkOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return 1;
    else
        return 0;
}

int pecendence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

char *Infix_to_postfix(string exp)
{
    struck *element = intialised(exp);
    int i, j;
    for (i = 0; exp[i]; ++i)
        ;
    char *postfix = (char *)malloc((i + 1) * sizeof(char));
    i = 0;
    j = 0;
    while (exp[i])
    {
        if (checkOperator(exp[i]))
        {
            if (pecendence(exp[i]) > pecendence(struckTop(element)))
            {
                push(element, exp[i]);
                ++i;
            }
            else
            {
                postfix[j] = pop(element);
                ++j;
            }
        }

        else
        {
            postfix[j] = exp[i];
            ++j;
            ++i;
        }
    }
    while (!isEmpty(element))
    {
        postfix[j] = pop(element);
        ++j;
    }
    postfix[j] = '\0';
    printf("%s\n", postfix);
    del(element);
    return postfix;
}
