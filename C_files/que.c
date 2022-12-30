#include <stdio.h>
int f(int );
int g(int );

int f(int x)
{
    if(x==1) return 1;
    else return( f(x-1)+2*g(x-1));
}
int g(int x)
{
    if(x==1) return 0;
    if(x==2) return -1;
    else return (g(x-1)-2*f(x-2));
}
int main()
{
    int x;
    printf("Enter n :");
    scanf("%d",&x);
    if(x>0) printf("f(%d)=%d , g(%d)=%d",x,f(x),x,g(x));
    return 0;
}
