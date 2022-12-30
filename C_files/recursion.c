//name-Debraj Das
//Roll no-21CH30010
//Calculation of Fibonacci series

#include <stdio.h>
#include <stdlib.h>

int fab(int x)
{
    if(x==1||x==2) return 1;
    else return fab(x-2)+fab(x-1);
}

int main()
{
    int x;
    printf("Enter the position : ");
    scanf("%d",&x);
    x=fab(x);
    printf("Number that position : %d",x);
    return 0;
}
