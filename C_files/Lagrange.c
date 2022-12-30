#include <stdio.h>
#include <stdlib.h>

int main()
 {
    double *point , *f , vaule ;
    int n , i ;
    while(1)
    {
    printf("Enter the degree of Interpolation polynomial : ");
    scanf("%d",&n);
    if(n==0) break;
    ++n;
    point= (double *)malloc(n*sizeof(double));
    f = (double *)malloc(n*sizeof(double));

    printf("Enter the point and corresponding function vaule :\n");
    for(i=0;i<n;++i)
    {
        printf("\t(x%d ,f%d)= ",i,i);
        scanf("%lf%lf",&point[i],&f[i]);
    }
    for(int j=0;j<n;++j)
    {
        vaule=1;
        for(i=0;i<n;++i)
        {
            if(i==j) continue;
            vaule*=(point[j]-point[i]);
        }
        vaule=(f[j]/vaule);
        printf("\n coefficient of %dth term is %lf",j,vaule);
    }
    printf("\n");
    free(point);
    free(f);
    printf("\nAgain computation is start.If you enter degree Zero(0) then computation exit.\n\n");
    }
    printf("\ncomputation is finished.\n");
    return 0;
 }