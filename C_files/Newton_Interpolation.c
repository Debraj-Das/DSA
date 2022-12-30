#include <stdio.h>
#include <stdlib.h>

int main()
 {
     double *point , *f ,vaule, x , mul ;
    int n , i ;
    while(1)
    {
    printf("Enter the no of given point for Newton Interpolation : ");
    scanf("%d",&n);
    if(n==0) break;
    point= (double *)malloc(n*sizeof(double));
    f = (double *)malloc(n*sizeof(double));

    printf("Enter the point and corresponding function vaule :\n");
    for(i=0;i<n;++i)
    {
        printf("\t(x%d ,f%d)= ",i,i);
        scanf("%lf%lf",&point[i],&f[i]);
    }
    
    for(int j=1,k=n-1;k>=0;++j,--k)
    {
        printf("\ta(%d) = %lf\n",j-1,f[0]);
        mul=f[0];
        for(i=0;i<k;++i)
        {
            f[i]=(f[i+1]-f[i])/(point[i+j]-point[i]);
        }
        f[k]=mul;
    }
            // calculation output vaule of user given point.
    while(1)
    {
        printf("\nEnter the output point :");
       scanf("%lf",&x);
       if(x==0) break;
       vaule=0;
       for(i=0;i<n;++i)
       {
        if(i==0) mul=1;
        else  mul*=(x-point[i-1]);

        vaule+=(mul*f[n-i-1]);
       }
    printf("\n vaule of function at x=%lf is %lf.\n",x,vaule);
    printf("\n Again you computed another point If you want again computation \n Then enter output Zero.\n");
    }
    
    free(point);
    free(f);
    printf("\n\nAgain computation is start.If you enter degree Zero(0) then computation exit.\n\n");
    }
    printf("\ncomputation is finished.\n");
    return 0;
 }