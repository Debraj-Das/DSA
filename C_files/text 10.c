//name-Debraj Das
//roll no-21CH30010

#include <stdio.h>
#include <math.h>

double fn(double );
void ran(double );
void fond(double,double );

double a,b,c,d;

double fn(double x)
{
    return (a*x*x*x+b*x*x+c*x+d);
}

int main()
{
    double x,y;
    while(1)
    {
        printf("Enter the coefficient of cubic of x : ");
        scanf("%lf",&a);
        if(a==0) break ;
        printf("Enter the coefficient of squard of x : ");
        scanf("%lf",&b);
        printf("Enter the coefficient of x : ");
        scanf("%lf",&c);
        printf("Enter the coefficient constant : ");
        scanf("%lf",&d);
        printf("Root of the Given Equation are :");
        if(a<0)
        {
            a = -a;
            b =-b;
            c =-c;
            d=-d;
        }
        if(b*b<3*a*c)  ran(0);
        else if(b*b>3*a*c)
        {
           x=(-b-sqrt(b*b-3*a*c))/(3*a);
            y=(-b+sqrt(b*b-3*a*c))/(3*a);
            if(fn(x)*fn(y)>0.0001)
            {
                if(fn(x)>0) ran(y);
                else ran(x);
            }
            else if(fn(x)*fn(y)<-0.0001)
            {
                ran(x);
                ran(y);
                fond(x,y);
            }
            else
            {
                if(fn(x)< 0.0001&&fn(x)> -0.0001)
                {
                    printf("%0.3lf ",x);
                    ran(y);
                }
                else
                {
                    printf("%0.3lf  ",y);
                    ran(x);
                }
            }
        }
        else
        {
            ran(-b/(3*a));
        }
        printf(".\n\nIf you want exit from execution then enter the coefficient of cubic of x Zero.\n\n");
    }
    printf("Execution is completed.\n");

    return 0;
}

void ran(double p)
{
    if(fn(p)<0)
    {
        while(fn(p)<0)
        {
            ++p;
            if(fn(p)< 0.0001&&fn(p)> -0.0001)
            {
                printf("  %0.3lf",p);
                return ;
            }
        }
        fond(p-1,p);
        return ;
    }
    if(fn(p)>0)
    {
        while(fn(p)>0)
        {
            --p;
            if(fn(p)< 0.0001&&fn(p)> -0.0001)
            {
                printf("  %0.3lf",p);
                return ;
            }
        }
        fond(p,p+1);
        return ;
    }
    if(fn(p)< 0.0001&&fn(p)> -0.0001)
    {
        printf("  %0.3lf",p);
        return ;
    }
}

void fond(double x,double y)
{
    double i;
    while(1)
    {
        i=(fn(x)*(y-x)/(fn(x)-fn(y)))+x ;
        if(fn(i)< 0.0001&&fn(i)> -0.0001)
        {
            printf("  %0.3lf",i);
            return ;
        }
        else
        {
            if(fn(i)*fn(x)>0) x=i;
            else  y=i;
        }
    }
}


