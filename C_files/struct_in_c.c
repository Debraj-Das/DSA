#include <stdio.h>
#include <stdlib.h>

typedef struct       //* structure in c languege with typedeg.
{
    double x ;
    double y ;
} two_dimension ;

int main()
{
    two_dimension point ;
    printf("Enter the (x , y) :: ");
    scanf("%lf%lf",&point.x,&point.y);
    printf("Enter point vector form :: %lf i + %lf j.\n",point.x,point.y);
    return 0;
}