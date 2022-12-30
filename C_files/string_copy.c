#include <stdio.h>
#include <stdlib.h>

char *getstring(char end);
char *string_copy(const char *string) ;
int string_len(const char *string)
{
    register int i ;
    for(i=0;string[i];++i);
    return (i+1) ;
}


int main()
{
    printf("Enter ending char of string ::");
    char *name, end = getchar();
    printf("Enter the string :: \n\t");
    name = getstring(end);
    char *cpstring = string_copy(name) ;
    printf("print of copy string ::\n%s\n\n",cpstring);
    free(cpstring);
    free(name);
    return 0;
}

char *string_copy(const char *string)
{
    char *copy_string = (char *)malloc(string_len(string)*sizeof(char ));
    register int i ;
    for(i=0;string[i];++i) 
       copy_string[i] = string[i];
    copy_string[i] = '\0';
    return copy_string ;
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
