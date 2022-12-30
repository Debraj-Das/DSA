/*Name-Debraj Das
 Roll no-21CH30010
 Q: Typecasting and float number store problem and appromate*/
#include <stdio.h>

int main()
{   float a;
    int b ;
    scanf("%f%d",&a,&b);
    printf("print float number %0.2f\n print whole number %d\n",a,b);
    a=(float)b;
     printf("second time print float number %0.2f\n print whole number %d",a,b);
    return 0;
}
