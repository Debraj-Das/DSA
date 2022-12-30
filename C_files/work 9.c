//Debraj Das
//Roll no-21CH30010
#include <stdio.h>
#include <math.h>

int main()
{
   double x,y,a,b,d;
   printf("The first coordinated:");
   scanf("%lf%lf",&x,&y);
   printf("The second coordinated:");
   scanf("%lf%lf",&a,&b);
   d=sqrt(pow(x-a,2)+pow(y-b,2));
   printf("Distance between two point is %lf",d);
    return 0;
}
