#include <stdio.h>

int main()
{
    float x;
    int y,i;
    printf("Enter The Number :");
    scanf("%f",&x);
    y=x;
    x=x-y;
    i=0;
    while(x!=0.00)
    {
        x=x*2;
        y=x;
       x=x-y;
        ++i;
    }
    printf("%d",i);
    return 0;
}
