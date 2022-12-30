#include <stdio.h>
#include <stdlib.h>

typedef struct       //* structure in c languege with typedeg.
{
    double x ;
    double y ;
} two_dimension ;

two_dimension sum_vector(two_dimension point[])   //# sum of the two vector.
{
    two_dimension sum ;
    sum.x = point[0].x + point[1].x ;
    sum.y = point[0].y + point[1].y ;
    return sum ; 
}

int main()
{
    two_dimension point[2] , sum ;
    printf("Enter first vector (x , y) :: ");
    scanf("%lf%lf",&point[0].x,&point[0].y);
    printf("Enter second vector (x , y) :: ");
    scanf("%lf%lf",&point[1].x,&point[1].y);
    sum = sum_vector(point) ;
    printf("Enter point vector form :: %0.2lf i + %0.2lf j.\n",sum.x,sum.y);
    return 0;
}