//name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>

typedef struct string_node
{
    int x;
    int y;
    struct string_node *next;
} string_node;

int main()
{
    int r,c,t,i,j;
    char **a;
    string_node *head,*p,*q,*n;
    while(1)
    {
        printf("Enter no. of rows, no. of columns and expected percentage of 1's: ");
        scanf("%d%d%d",&r,&c,&t);
        if(r==0||c==0) break ;
        printf("Enter seed: ");
        scanf("%d",&i);
        srand(i);
        a=(char **)malloc(r*sizeof(char *));
        for(i=0; i<r; i++)
        {
            a[i]=(char *)malloc(c*sizeof(char ));
            for(j=0; j<c; ++j)
            {
                if(t<rand()%100) a[i][j]='-';
                else a[i][j]='1';
            }
        }
        a[0][0]=a[0][c-1]='1';
        printf("\n\nInput array: \n\t");
        for(i=r-1; i>=0; --i)
        {
            for(j=0; j<c; ++j)
            {
                printf("%c ",a[i][j]);
            }
            printf("\n\t");
        }
        head=(string_node *)malloc(sizeof(string_node));
        head->x=head->y=0;
        head->next=NULL;
        q=head;
        a[0][0]='2';
        for(j=0; j<c; ++j)
        {
            for(i=r-1; i>=0; --i)
            {
                if(a[i][j]=='1'&&(i+j)!=0)
                {
                    a[i][j]='2';
                    p=(string_node *)malloc(sizeof(string_node));
                    p->x=j;
                    p->y=i;
                    p->next=NULL;
                    q->next=p;
                    q=p;
                    break ;
                }
            }
        }
        if(a[0][c-1]!='2')
        {
            a[0][c-1]='2';
            p=(string_node *)malloc(sizeof(string_node));
            p->x=c-1;
            p->y=0;
            p->next=NULL;
            q->next=p;
            q=p;
        }
        printf("\n\nList of points: \n\t");
        t=0;
        p=head;
        while(p!=NULL)
        {
            printf("(%d,%d) ",p->x,p->y);
            p=p->next;
            ++t;
            if(t>6){
                t=t%6;
                printf("\n\t");
            }
        }
        q=head;
        p=q->next;
        n=p->next;
        while(n!=NULL)
        {
            if((p->y-q->y)*(n->x-p->x)<=(n->y-p->y)*(p->x-q->x))
            {
                a[p->y][p->x]='1';
                q->next=n;
                free(p);
                p=q;
                q=head;
                while(q->next!=p)
                {
                    q=q->next;
                }
            }
            else
            {
                q=p;
                p=n;
                n=n->next;
            }
        }
        printf("\n\nVertices:  \n\t");
        t=0;
        p=head;
        while(p!=NULL)
        {
            printf("(%d,%d) ",p->x,p->y);
            p=p->next;
            ++t;
            if(t>6){
                t=t%6;
                printf("\n\t");
            }
        }
        printf("\n\nOutput array: \n\t");
        for(i=r-1; i>=0; --i)
        {
            for(j=0; j<c; ++j)
            {
                printf("%c ",a[i][j]);
            }
            printf("\n\t");
        }
        q=head;
        while(q!=NULL)
        {
            p=q;
            q=q->next;
            free(p);
        }
        printf("\nAgain process in excess,\nIf you want to exit form the process than input or column is Zero,\n\n");
    }
    printf("\nProcess is terminated,\n");
    return 0;
}
