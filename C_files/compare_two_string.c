#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    printf("Enter ending char of string ::");
    char *name, end = getchar();
    printf("Enter the first string :: \n\t");
    name = getstring(end);
    printf("Enter the second string :: \n\t");
    char *name2 = getstring(end);
    int i = strlen(name) , j = strlen(name2);
    if (i>j)
        printf("First string is big.\n");
    else if (i<j)
        printf("Second string is big.\n");
    else
        printf("Both are equal size.\n");

    free(name);
    free(name2);
    return 0;
}