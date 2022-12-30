//name-Debraj Das
//roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>

typedef struct string_node
{
    int x;
    int y;
    struct string_node *next;
} string_node;

void in(int x,int y,string_node *head,char **a)
{
    static string_node *p,*q;
    if(head->next==NULL)
    {
        q=head;
        p=(string_node *)malloc(sizeof(string_node ));
        p->x=x;
        p->y=y;
        p->next=NULL;
        head->next=p;
        a[q->y][q->x]='2';
        a[p->y][p->x]='2';
        return ;
    }
    else if((p->y-q->y)>(y-p->y))
    {
        q=p;
        p=(string_node *)malloc(sizeof(string_node ));
        p->x=x;
        p->y=y;
        p->next=NULL;
        q->next=p;
        a[q->y][q->x]='2';
        a[p->y][p->x]='2';
        return ;
    }
    else
    {
        a[p->y][p->x]='1';
         p->x=x;
        p->y=y;
        return ;
    }

}

int main()
{
    char **a;
    int i,j,r,c,t,s;
    string_node *head,*p,*q;
    printf("Enter no. of rows, no. of columns and expected percentage of 1's:");
    scanf("%d%d%d",&r,&c,&t);
    printf("Enter seed: ");
    scanf("%d",&s);
    srand(s);
    a=(char **)malloc(r*sizeof(char *));
    for(i=0; i<r; ++i)
    {
        a[i]=(char *)malloc(c*sizeof(char ));
        for(j=0; j<c; ++j)
        {
            if(t<=rand()%100) a[i][j]='1';
            else a[i][j]='-';
        }
    }
    a[0][0]=a[0][c-1]='1';
    printf("\n\nInput array :\n");
    for(i=r-1; i>=0; i--)
    {
        for(j=0; j<c; j++) printf("%c ",a[i][j]);
        printf("\n");
    }
    head=(string_node *)malloc(sizeof(string_node ));
    head->x=0;
    head->y=0;
    head->next=NULL;
    printf("\n\nList of points:\n (0,0)");
    a[0][0]='2';
    for(j=0; j<c; ++j)
    {
        for(i=r-1; i>=0; --i)
        {
            if(a[i][j]=='1'&&(i+j)!=0)
            {
                in(j,i,head,a);
                printf("(%d,%d)",j,i);
                break ;
            }
        }
    }
    if(a[0][c-1]!='2')
    {
        printf("(%d,%d)",c-1,0);
        a[0][c-1]='2';
        q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        p=(string_node *)malloc(sizeof(string_node ));
        p->x=c-1;
        p->y=0;
        p->next=NULL;
        q->next=p;
    }
    printf("\n\nVertices: \n");
     q=head->next;
    while(head->next!=NULL)
    {    p=q->next;
        if((q->y-head->y)>(p->y-q->y))
        {
            head->next=p;
            free(q);
        }
        printf("(%d,%d)",head->x,head->y);
        head=head->next;
    }
    if(head->x==c-1&&head->y==0) printf("(%d,%d)",head->x,head->y);
    else
    {
        printf("(%d,%d)",head->x,head->y);
        printf("(%d,%d)",0,c-1);
    }
    printf("\n\nOutput array :\n");
    for(i=r-1; i>=0; i--)
    {
        for(j=0; j<c; j++) printf("%c ",a[i][j]);
        printf("\n");
    }

    return 0;
}
