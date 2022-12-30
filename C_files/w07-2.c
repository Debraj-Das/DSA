/*Name-Debraj Das
Roll no-21CH30010
 */

#include <stdio.h>

int h=0,f,g,j;
void cou(int x[],int y[],int p,int q,int z,int n)
{
    int i;
    x[z]=p;
    y[z]=q;

    if(p<n&&q<n) cou(x,y,p+1,q+1,z+1,n);
    else
    {
        printf("%d.",++h);
        for(i=0; i<=z; ++i)
        {
            printf("(%d,%d)",x[i],y[i]);
        }
    printf("\n");
            f=z;


    }
    if(q<=n&&p<n) cou(x,y,p+1,q,z+1,n);
    else
    {
        printf("%d.",++h);
        for(i=f; i<=z; ++i)
        {
            printf("(%d,%d)",x[i],y[i]);
        }
         printf("\n");
            g=z;
    }
    if(q<n&&p<=n) cou(x,y,p,q+2,z+1,n);
    else
    {
        printf("%d.",++h);
        for(i=g; i<=z; ++i)
        {
            printf("(%d,%d)",x[i],y[i]);
        }
         printf("\n");
            j=z;
    }
}

int main()
{
    int n,x[100],y[100],p=0,q=0,z=0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    cou(x,y,p,q,z,n);
    return 0 ;
}
