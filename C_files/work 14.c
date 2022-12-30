//Name:Debraj Das
//Roll No-21CH30010

#include <stdio.h>

int main()
{
   int a,b,c;
   printf("Three integer are:");
   scanf("%d%d%d",&a,&b,&c);
   if((a<b&&a>c)||(a>b&&a<c))
    printf("Median=%d",a);
    if((b<a&&b>c)||(b>a&&b<c))
    printf("Median=%d",b);
    else
        printf("Median=%d",c);
    return 0;
}
