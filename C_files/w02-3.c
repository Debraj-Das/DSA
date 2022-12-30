//Name:Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
    int x,a,b,c,d;
    printf("Enter a positive number:");
    scanf("%d",&x);
    a=(x/1000),b=((x/100)%10),c=((x/10)%10),d=(x%10);
    printf("%d\n%d\n%d\n%d",(1000*d+100*a+10*b+c),(1000*c+100*d+10*a+b),(1000*b+100*c+10*d+a),(1000*a+100*b+10*c+d));
    return 0;
}
