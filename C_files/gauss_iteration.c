#include <stdio.h>
#include <stdlib.h>

long long int truncated=1 ;  //truncated after n decimal place without rounding off
double *x ;

void iteration()
{
    int vaule ;

   x[0]=(85-6*x[1]+x[2])/27; 
    vaule =(x[0]*truncated);
    x[0]=((double)vaule/truncated);

   x[1]=(72-6*x[0]-2*x[2])/15;
   vaule =(x[1]*truncated);
    x[1]=((double)vaule/truncated);

   x[2]=(110-x[0]-x[1])/54; 
   vaule =(x[2]*truncated);
    x[2]=((double)vaule/truncated);

}

int main()
 {
    int no_iteration=2 ;
    int n=3 ; // number of varible.
    int i;
    for(i =0;i<4;++i)  // need decimal number put in looping constant.
    {
       truncated*=10;
    }

    x=(double *)malloc(n*sizeof(double));

   for(i=0;i<n;++i)
    {
        printf("Enter the x[%d]= ",i+1);
        scanf("%lf",&x[i]);
    }
    for(i=0;i<no_iteration;++i)
    {
        iteration();
    printf("\n\nvaule of variable after %dth iteration using the Gauss-Seidel method\n\n",i+1);
    for(int j=0;j<n;++j)
    {
        printf("\tx[%d]=%lf\n",j+1,x[j]);
    }
    }
    free(x);
    return 0;
 }