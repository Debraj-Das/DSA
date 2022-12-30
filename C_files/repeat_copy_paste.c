// This file's executable file name rcp.exe(for command) and repeat_copy_paste.exe(for general).

#include <stdio.h>
#include <stdlib.h>

char *getstring(char argv[]) // Pass the finished character as a argument of getstring function.
{
    typedef struct segment
    {
        char a[32];
        struct segment *next;
    } string_node;

    FILE *fptr;
    fptr = fopen(argv, "r");
    if (fptr == NULL)
    {
        printf("Error! for opening Prob_doc.txt\n.");
        exit(1);
    }

    string_node *head, *p;
    char ch, *string;
    int n = 0, i = 0, j;
    p = (string_node *)malloc(sizeof(string_node));
    head = p;
    while (fscanf(fptr, "%c", &ch) != EOF)
    {
        p->a[i] = ch;
        ++i;
        if (i > 31)
        {
            p->next = (string_node *)malloc(sizeof(string_node));
            p = p->next;
            n += i;
            i = 0;
        }
    }
    p->a[i] = '\0';
    n += (++i);
    p->next = NULL;
    string = (char *)malloc(n * sizeof(char));
    p = head;
    for (i = 0, j = 0; j < n; ++i, ++j)
    {
        string[j] = p->a[i];
        if (i >= 31)
        {
            head = p;
            p = p->next;
            free(head);
            i = -1;
        }
    }
    free(p);
    fclose(fptr);
    return string;
}

int main(int argc, char *argv[])
{
    int n;
    FILE *fpta;
    printf("If you want to overwrite the 2nd copy give input 1.\nIf not and only paste at end then give input 2.\n");
    printf("\tEnter input : ");
    scanf("%d", &n);
    if (n == 1)
        fpta = fopen(argv[2], "w");
    else
        fpta = fopen(argv[2], "a");
    if (fpta == NULL)
    {
        printf("Error! for opening file copt.txt.\n");
        exit(1);
    }
    printf("Enter the number you want to paste the copy data : ");
    scanf("%d", &n);
    char *string;
    string = getstring(argv[1]);
    for (int i = 0; i < n; ++i)
        fprintf(fpta, "%s\n", string);
    printf("copy paste is finished %d time.\n", n);
    free(string);
    fclose(fpta);

    return 0;
}
