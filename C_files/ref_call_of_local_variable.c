#include <stdio.h>
#include <stdlib.h>

void average_sum(double *sum,double *average)
{
    (*sum)+=(*average) ;
    (*average) = (*sum)/2 ;
    return ;
}

double main()
{
    double a , b ;
    printf("Enter two number :: ");
    scanf("%lf%lf",&a,&b);
    average_sum(&a,&b);
    printf("sum = %lf and average = %lf\n",a,b);
    return 0;
}