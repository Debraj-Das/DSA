//name-Debraj Das
//roll no-21CH30010
// parentheses matching code.

#include <stdio.h>
#include <stdlib.h>

typedef struct string_node
{
    char a;
    struct string_node *next ;
} string_node;

int main()
{
    char c;
    string_node *head, *p;
    head =NULL;
    c=getchar();
    while(c!='\n')
    {
        if(c=='('||c=='{'||c=='[')
        {
            p=head;
            head= (string_node *)malloc(sizeof(string_node ));
            head->a=c;
            head->next=p;
        }
        else if(c==')'||c=='}'||c==']')
        {
           if(c-1==head->a)
           {
               p=head;
               head =head->next;
               free(p);
           }
            else
            {
                printf("parentheses are not well defined.");
              return 0;
            }
        }
         c=getchar();
    }
    if(head !=NULL)  printf("parentheses are not well defined.");
    else  printf("parentheses are well defined.");
    return 0;
}
