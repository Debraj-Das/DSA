/*Name-Debraj Das
  Roll no-21CH30010 */

#include <stdio.h>


typedef struct
{

    int x;
    int y;
    int c;
} date;
void sorting(date a[],int n)
{
    int i, j;
    date t;
    for (i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; ++j)
        {
            if (a[j].x>a[j+1].x)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
            if(a[j].x==a[j+1].x && a[j].y > a[j+1].y)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        return ;
    }




}

int main()
{
    date  a[20],b[10];
    int i=0,j,n,m,p;
    printf("Input polynomial 1:\n");
    while(1)
    {
        printf("Enter exponent of x, exponent of y and coefficient: ");
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
        if(a[i].c==0)
        {
            n=i;
            break ;
        }
        ++i;
    }
    sorting(a,n);
    printf("Polynomial 1:\n");
    for (j=0; j<n; ++j)
    {
        printf("(%d,%d,%d)\n",a[j].x,a[j].y,a[j].c);
    }


    i=0;
    printf("Input polynomial 2:\n");
    while(1)
    {
        printf("Enter exponent of x, exponent of y and coefficient: ");
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].c);
        if(b[i].c==0)
        {
            m=i;
            break ;
        }
        ++i;
    }
    sorting(b,m);
    printf("Polynomial 2:\n");
    for (j=0; j<m; ++j)
    {
        printf("(%d,%d,%d)\n",b[j].x,b[j].y,b[j].c);
    }
    for (j=0,p=m; j<m; ++j)
    {
        for(i=0; i<n; ++i)
        {
            if(a[i].x==b[j].x && a[i].y==b[j].y)
            {
                a[i].c+=b[j].c;
                --p;
                b[j].x=b[m].x+1;
            }
        }
    }
    sorting(b,m);
    for(j=0; n<n+p; ++n)
    {
        a[n]=b[j];
        ++j;
    }
    sorting(a,n);
    printf("Sum: \n");
    for (j=0; j<n; ++j)
    {
        printf("(%d,%d,%d)\n",a[j].x,a[j].y,a[j].c);
    }



    return 0;
}
