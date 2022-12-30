#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int *a,n;
    printf("Enter the input number : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int ));
        printf("Enter the number one by one : \n");
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0,*t,swep;i<n;++i)
    {
            t=&a[i];
        for(int j=i+1;j<n;++j)
        {
            if(*t>a[j])
            {
                t=&a[j];
            }
        }
        swep=a[i];
        a[i]=*t;
        *t=swep;
    }
    printf("Arrange the date by sorting Method \n");
    for(int i=0;i<n;++i) 
    {
        printf("%d th member %d \n",i+1,a[i]);
    }
    return 0;
 }