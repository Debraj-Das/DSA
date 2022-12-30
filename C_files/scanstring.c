#include <stdio.h>
#include <stdlib.h>

char *getstring(char finish)     // Pass the finished character as a argument of getstring function.
{
    typedef struct segment
  {
    char a[32];
    struct segment *next;
  } string_node ;

    string_node *head ,*p ;
    char c,*string ;
    int n=0 ,i=0 ,j;
    p=(string_node *)malloc(sizeof(string_node ));
    head=p;
    do
    {
        scanf("%c",&c);
        p->a[i] = c ;
        ++i;
        if(i>31)
        {
            p->next=(string_node *)malloc(sizeof(string_node ));
            p=p->next;
            n+=i;
            i=0;
        }
    } while (c!=finish);
    n+=(--i) ;
    p->a[i] = '\0' ;
    p->next=NULL;   
    string=(char *)malloc(n*sizeof(char ));
    p=head;
    for(i=0,j=0;j < n;++i,++j)
    {
        string[j]=p->a[i] ;
        if(i>=31)
        {
            head=p;
            p=p->next;
            free(head);
            i=-1;
        }
    }
    free(p);
    return string;
}

int main()
 {
    char *string ;
    printf("Enter the string : \n\t");
    string= getstring('#');
    printf("\n\n\t%s\n",string);
    return 0;
 }