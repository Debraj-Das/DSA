/* Name-Debraj Das
Roll no-21CH30010 */

#include <stdio.h>

void rel(int a[][10],int r[],int n,int p)
{
    int i;
    if(r[p]==r[0])  return;
    for(i=0; i<n; ++i)
    {
        if(a[r[0]-1][i-1]==1)
        {
            rel(a,r,n) ;
            ++p;
        }
    }

    return ;
}
int main()
{
    int a[10][10],i,j,m,x,y,b[10],c[10],p,q;
    for(i=0; i<10; ++i)
        for(j=0; j<10; ++j)
            a[i][j]=0;
    printf("How many people and friendships? ");
    scanf("%d%d",&i,&j);

    for(m=0,m<j; ++m)
    {
        printf("Enter the two guests participating in friendship %d: ",m+1);
        scanf("%d%d",&x,&y);
        a[x-1][y-1]= a[y-1][x-1]=1;
    }
    for(m=1; m<=i; ++m)
    {
        if(m==1)
        {
            b[0]=m;
            p=1;
            rel(a,b,i,p);
        }
        else
        {
            c[0]=m;
            q=1;
            rel(a,c,i,q);
        }
    }
    if(q>p)
    {
        for(i=0; i<q; ++i)
        {
            b[i]=c[i];
            p=q;
        }
    }
    printf("Largest friendship group:");
    for(i=0; i<p; ++i)
        scanf("%d",b[i]);
    printf("Size=%d",p);

    return 0;
}
