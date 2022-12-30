/*name-Debraj Das
  roll no-21CH30010*/

#include <stdio.h>

int main()
{
    int x,a,b,c,d;
    printf("Enter the positive integer number : ");
    scanf("%d",&x);
    a=x/1000;
    b=(x/100)%10;
    c=(x/10)%10;
    d=x%10;
    printf("%4d\n",1000*d+100*a+10*b+c);
    printf("%4d\n",1000*c+100*d+10*a+b);
    printf("%4d\n",1000*b+100*c+10*d+a);
    printf("%4d\n",1000*a+100*b+10*c+d);
    return 0;
}
