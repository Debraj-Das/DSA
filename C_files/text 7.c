/* Name-Debraj Das
  Roll no-21Ch30010
  Q: question for operator precedence.*/

#include <stdio.h>

int main()
{   int a,b;
    printf("Enter one number : ");
    scanf("%d",&a);  b=a;
    printf("print ++a =%d.\n",++a);
    printf("a=%d\n",a); a=b;
    printf("print a++=%d.\n",a++);
    printf("a=%d\n",a); a=b;
    printf("print 0-++a=%d.\n",0-++a);
    printf("a=%d\n",a); a=b;
    printf("print 0-a++=%d.\n",0-a++);
    printf("a=%d\n",a); a=b;
    printf("print ++a-++a=%d.\n",++a-++a);
    printf("a=%d\n",a); a=b;
    printf("print ++a-a++=%d.\n",++a-a++);
    printf("a=%d\n",a); a=b;
    printf("print a++-++a=%d.\n",a++-++a);
    printf("a=%d\n",a); a=b;
    printf("print a++-a++=%d.\n",a++-a++);
    printf("a=%d\n",a);  a=b;
    printf("%d",a+++(0-a++));
    printf("a=%d\n",a);
    return 0;
}
