#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string ;

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
            if ((ch == '\n')||(ch == ' '))
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
            if ((ch == '\n')||(ch == ' '))
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
    printf("Enter the word :: ");
    string word = getstring();
    int word_lenth = strlen(word);
    const int middle = (word_lenth/2);
    for(register int i = 0 ; i<middle;++i)
    {
        if(word[i]!=word[word_lenth-1-i])
        {
            printf("%s is not pandrome word.\n\n",word);
            free(word);
            exit(0);
        }
    }
    printf("%s is a pandrome word.\n\n",word);
    free(word);
    return 0;
}