#include <stdio.h>
#include <stdlib.h>

int n;
double *p;

 double poly( double r)
{ 
   double t=1.0; 
    double s=0.0;
for(int i=0;i<=n;i++)
{
    s+=(t*p[i]);
     t*=r;
}
return s;
}

int main()
{
    int i=1;
   double a , x , y ,value ,desimal;
    while(i)
   {
    printf("\nEnter the degree of the polynomial : ");
    scanf("%d",&n);    //accepting the degree of the polynomial

    p = ( double*)malloc((n+1)*sizeof( double ));   //making an array to accept n+1 coefficients
    for(i=0;i<=n;i++)
    {
            printf("Input the %dth coefficient of the polynomial : ",i);
            scanf("%lf",&p[i]);

    }
    printf("Want to find roots between?");
    printf("\n\t");
    scanf("%lf",&x);
    printf("\t");
    scanf("%lf",&y);
    printf("Number of Zero  after desimal of function :  ");
    scanf("%d",&i);
    desimal=0.1;
    while(i)
    {
        desimal*=0.1;
        --i;
         printf("desimal number is %0.8lf \n",desimal);
    }
      value=1;
    for(i=0;value>desimal;i++)
    {   
        value =poly((x+y)/2.0);
        a =poly(x);
        if((a*value)<0.0)
        {  
            if(a>0) value*=(-1);
             y=(x+y)/2.0;
        }
        else 
        {
            if(a<0) value*=(-1);
           x=(x+y)/2.0;
        }
    }
    printf("\nThe root between %lf and %lf after %d iterations.\n",x,y,i);
    printf("\nCorresponding Value of polynomial are %lf and %lf.\n",poly(x),poly(y));
    free(p);
    printf("\n\n Process again start if you want to exit form process then Enter Zero or want procude Enter nonzero.");
    printf("\n\t Enter input : ");
    scanf("%d",&i);
   }
   printf("\nComputation is finished.");
}