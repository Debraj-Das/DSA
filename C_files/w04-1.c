//Name:Debraj Das
//Roll no-21CH30010
//Question-w03-1.c

#include <stdio.h>

int main()
{
    int a,b;
    printf("Enter a and b :");
    scanf("%d%d",&a,&b);
    printf("continued fraction [%d",a/b);
    a=a%b;
    if(a!=0) printf(";");
    while(a!=0&&b!=0) {
   if(a!=0)
        {printf(", %d",b/a), b=b%a;}
   if(b!=0)
    {printf(", %d",a/b), a=a%b ;}
    }
    printf("]");
    return 0;
}
