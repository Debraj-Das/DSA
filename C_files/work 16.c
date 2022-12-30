//Name:Debraj Das
//Roll no-21H30010
//expression pdf question 2.
#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
    printf("first row expression's result %d\nMy first manual expression's result %d\n",(a+b/c/d*10*5-b+20*d/c),(a+(((b/c)/d)*10)*5-b+(20*d)/c));
    printf("second row expression's result %d\nMy second manual expression's result %d\n",(a&&b||c&&d>a||c<=b),(((a&&b)||(c&&(d>a)))||(c<=b)));
    return 0;
}
