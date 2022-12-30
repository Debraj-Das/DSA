#include <stdio.h>
#include <stdlib.h>

double part(double );
double fraction(double );

int main()
{
    double n,b,out;
    while(1)
    {
        printf("Enter the vaule of M and base of log(M) respectively (M,base) : ");
         scanf("%lf%lf", &n, &b);
        if(n<=0||b<=0||b==1) break ;
        out = part(n)/part(b);
        printf("Value of logarithm(%lf) of base(%lf) =%lf.\n\n",n,b,out);
        printf("Process again start.\n");

    }
    printf("\nProcess is finish.");
    return 0;
}

double part(double n)
{
    double sum ;
    --n;
    if(n==1) sum=0.69314718 ;
    else if(n<1) sum=fraction((double)n);
    else
    {    
        double x ;
         x=1/(double)n;
        sum=fraction(x)+part(n);
    }
    return sum;
}

double fraction(double x)
{
    double y=x,re;
    int i;
    for(i=1,re=0; (y>(1e-16))||(y<(-1e-16)); ++i)
    {
        re+=y/i;
        y*=(-x);
    }
    return re;
}

