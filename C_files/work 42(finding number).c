//name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
    int n,y,i,sum;
    while(1)
    {
        printf("If you want exit the execution.\nNumber of enter number : ");
        scanf("%d",&n);
        if(n==0) break ;
        printf("Enter the number : ");
        for(i=0,sum=0; i<n; ++i)
        {
            scanf("%d",&y);
            sum+=y;
        }
        for(i=1,y=0; i<n+2; ++i) y+=i;
        for(i=1; i<n+2; ++i)
        {
            if(sum==y-i)
            {
                printf("Missing number is %d\n\n",i);
                n=0;
                break ;
            }
        }
        if(n)    printf("\nEntering any number is/are wrong.\n\n");
    }
    return 0;
}
