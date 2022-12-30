#include <stdio.h>
#include <stdlib.h>

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

int main(int agc, char *arv[])
{
    if (agc == 1)
        exit(1);
    FILE *chack = fopen(arv[1],"r");
    if(chack != NULL) 
    {
        printf("you want to not overwrite then enter 'n' :: ");
        char c = getchar() ;
        if(c == 'n')  exit(1);
    }

    char end, *s;
    printf("Enter end point :: ");
    scanf("%c", &end);
    while (getchar() != '\n')
        ;
    printf("Enter the string ::\n\t ");
    s = getstring(end);

    int n;
    printf("Enter no to enter the text :: ");
    scanf("%d", &n);

    FILE *fptw;
    fptw = fopen(arv[1], "w");
    for (int i = 0; i < n; ++i)
        fprintf(fptw, "%s\n", s);
    fclose(fptw);

    // FILE *f_p_r = fopen("text.txt", "r");
    // for (char s; fscanf(f_p_r, "%c", &s) != EOF; printf("%c", s))
    //     ;
    // fclose(f_p_r);

    return 0;
}
