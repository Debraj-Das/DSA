#include <stdio.h>
#include <stdlib.h>

char *getstring(char end);   //* This function used for get the string as input.

int main()
{
    printf("Enter ending char of string ::");
    char *name, end = getchar();
    while(getchar()!='\n') ;  //# This line of code use for clean the buffer.
    printf("Enter the string :: \n\t");
    name = getstring(end);
    printf("Enter the character which you want to count :: ");
    while(getchar()!='\n') ;  //# This line of code use for clean the buffer.
    char s = getchar();
    int n = 0 ;
    for(register int i = 0 ; name[i];++i)
      {
        if(name[i]==s)   
        {
            n = 1 ;
            break;
        }
      }
    if(n) printf("%c character is present in enter string.\n",s);
    else printf("%c is not present in entering chacteracter.\n",s);
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
