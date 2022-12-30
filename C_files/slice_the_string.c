#include <stdio.h>
#include <stdlib.h>

char *getstring(char end);
char *slice(char *string, int m, int n);
int string_length(const char *string)
{
    register int i;
    for (i = 0; string[i]; ++i)
        ;
    return i;
}

int main()
{
    printf("Enter ending char of string ::");
    char *name, end = getchar();
    printf("Enter the string :: \n\t");
    name = getstring(end);
    int m, n, lenth_of_string = string_length(name);
    printf("Enter a first number :: ");
    do
    {
        scanf("%d", &m);
    } while (m > lenth_of_string);

    printf("Enter the second number :: ");
    scanf("%d", &n);
    if (n > lenth_of_string)
        n = lenth_of_string;
    char *modified_string = slice(name, m, n);
    printf("After slice the string ::\n\t %s\n\n", modified_string);
    free(name);
    free(modified_string);
    return 0;
}

char *slice(char *string, int m, int n)
{
    char *s = (char *)malloc((n - m + 2) * sizeof(char));
    register int j=0 ;
    for (register int i = (m - 1) ; i < n; ++i, ++j)
        s[j] = string[i];
        s[j] = '\0';
    return s;
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
