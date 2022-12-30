#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int *a,n;
    printf("Enter the input number : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int ));
    printf("Enter the input one by one :\n");
    for(int i=0;i<n;++i)
    {
       scanf("%d",&a[i]);
    }
    for(int i=0,swep=0;i<n-1;++i)
    {
       for(int j=0,t;j<n-i-1;++j)
    {
       if(a[j]>a[j+1])
       {
          t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
        ++swep;
       }
    }
    if(swep==0) break;
    swep=0;
    }
    printf("Arrenge the date by bubble sorting :\n");
    for(int i=0;i<n;++i)
    {
       printf("%d th number %d \n",i+1,a[i]);
    }
    return 0;
 }