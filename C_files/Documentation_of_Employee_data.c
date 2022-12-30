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

int main(int argc , char *argv[])
{
   FILE *document_fpta ;
   if(argc == 1)
        document_fpta = fopen("Document_about_data.txt","a");
   else 
       document_fpta = fopen(argv[1],"a");
    if(document_fpta == NULL)
    {
        printf("Problem in created file.");
        exit(1);
    }
    int n ;
    printf("Enter the no of Employee :: ");
    scanf("%d",&n);
    fprintf(document_fpta,"Employee Name\t\t\t\tSalary ****\n");
    int i = 0 , salary ;
    for(char *str ;i<n;i++)
    {
        printf("%d) Name of Employee :: ",(i+1));
        while(getchar() != '\n');
         str = getstring('\n');
         printf("Salary of this person :: ");
         scanf("%d",&salary);
         fprintf(document_fpta,"%s\t\t\t\t%d\n",str,salary);
         free(str);
    }
    fclose(document_fpta);
    printf("Documentation of Employee data is finished.\n");
    return 0;
}
