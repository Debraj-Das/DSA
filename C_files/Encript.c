#include <stdio.h>
#include <stdlib.h>

char *getstring(char end);

int main()
{
    printf("Enter ending char of string ::");
    char *name, end = getchar();
    while(getchar()!='\n') ;
    printf("Enter the string :: \n\t");
    name = getstring(end);
    for(register int i=0;name[i];++i)
          name[i] += 1 ;
    printf("\nEncoded string is ::\n\t%s\n",name);
    free(name);
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
