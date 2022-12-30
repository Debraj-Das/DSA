//Name:Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <math.h>

int main()
{
int x,y,a,b;
double d;
printf("first coordinate:");
scanf("%d%d",&x,&y);
printf("second coordinate:");
scanf("%d%d",&a,&b);
d=sqrt(pow(x-a,2)+pow(y-b,2)) ;
printf("Distance between two point is %lf.",d);
    return 0;
}
