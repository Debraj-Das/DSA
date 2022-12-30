#include <stdio.h>
#include <stdlib.h>

 double *x , *y;

void iteration()
{
   y[0]=(-11-x[1]+2*x[2])/8; 
   y[1]=(22-2*x[0]-x[2])/9; 
   y[2]=(-15+x[0]+2*x[1])/11; 
}

int main()
 {
    long long int truncated=1 ,desimal ;  //truncated after n decimal place without rounding of
    int no_iteration=5 ;
    int n=3 ; // number of varible.
    int i,j;
    for(i =0;i<4;++i)  // need decimal number put in looping constant.
    {
       truncated*=10;
    }

    x=( double *)malloc(n*sizeof(double));
    y=(double *)malloc(n*sizeof(double));
   for(i=0;i<n;++i)
    {
        printf("Enter the x[%d]= ",i+1);
        scanf("%lf",&x[i]);
    }
    for(i=0;i<no_iteration;++i)
    {
        iteration();
        for(j=0;j<n;++j)
        {
            desimal=(y[j]*truncated);
           x[j]=((double)desimal/truncated);
        }
    printf("\nvaule of variable after %dth iteration using  by Jacobi's method\n\n",i+1);
    for(j=0;j<n;++j)
    {
        printf("\tx[%d]=%lf\n",j+1,x[j]);
    }
    }
    free(y);
    free(x);
    return 0;
 }