//Name:Debraj Das
//Roll no-21CH30010
//expression pdf question 3.
#include <stdio.h>
#include <math.h>

int main()
{
    double x1,y1,x2,y2,x3,y3,a;
    printf("Enter the three coordinate point in 2-d are :");
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("Area of the Triangle of those three point is %lf",a=(0.5*fabs((x1*y2-y1*x2)+(x2*y3-y2*x3)+(x3*y1-y3*x1))));
    return 0;
}
