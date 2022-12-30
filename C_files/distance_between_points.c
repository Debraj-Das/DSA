#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
 {
    double **point , distance ;
    register int i , j , no_dimention , no_point ;
    int  k  ;
    printf("Enter the no of point and  dimension of the space : ");
    scanf("%d",&k);
    no_point = k ;
    scanf("%d",&k);
    no_dimention = k ;
    point = (double **)malloc(no_point*sizeof(double *));
    for(i=0;i<no_point;++i)
    {
        point[i] = (double *)malloc(no_dimention*sizeof(double));
        printf("Enter the point(%d) : ",(i+1));
        for(j=0;j<no_dimention;++j)
        {
            scanf("%lf",&point[i][j]);
        }
    }
    for(k=0;k<(no_point-1);++k)
    {
       for(i=(k+1);i<no_point;++i)
       {
        for(distance =0,j=0;j<no_dimention;++j)
        {
            distance+=pow((point[k][j]-point[i][j]),2);
        }
        printf("Distance value of point %d & %d is %lf.\n",(k+1),(i+1),sqrt(distance));
       }
    }
    for(i=0;i<no_point;++i)
    {
        free(point[i]);
    }
    free(point);
    return 0;
 }