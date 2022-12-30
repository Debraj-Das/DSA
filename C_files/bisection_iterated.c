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
    int i=1,j;
   double a , b , x , y ,value ;
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
    scanf("%lf",&a);
    printf("\t");
    scanf("%lf",&b);
    printf("Number of iterations wanted? : ");
    scanf("%d",&j);

      x = a ;
      y = b ;
    for(i=0;i<j;i++)
    {   
        value =poly((x+y)/2.0);
        if(value == 0.00) break;
        else 
        {
        if((poly(x)*value)<0.0)
             y=(x+y)/2.0;
        else 
           x=(x+y)/2.0;
        }
    }
    printf("The root between %lf and %lf after %d iterations.\n",x,y,i);
    printf("\nCorresponding Value of polynomial are %lf and %lf.\n",poly(x),poly(y));
    free(p);
    printf("\n\n Process again start if you want to exit form process then Enter Zero or want procude Enter nonzero.");
    printf("\n\t Enter input : ");
    scanf("%d",&i);
   }
   printf("\nComputation is finished.");
}