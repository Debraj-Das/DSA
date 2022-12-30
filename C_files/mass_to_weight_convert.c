#include <stdio.h>
#include <stdlib.h>

int main()
{
    double mass, weight;
    printf("Enter the mass of the object :: ");
    scanf("%lf", &mass);
    printf("Weight of this object is %lf\n\n", (mass * 9.81));
    return 0;
}