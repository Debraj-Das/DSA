#include <stdio.h>
#include <stdlib.h>

typedef struct points
{
    double x ;
    double y ;
} pts ;


int getint()
{
    int ret ;
    scanf("%d",&ret);
    return ret ;
}

int main()
 {
    register int no_points , i ;
    pts *point ;
    printf("Enter the no of vertex of polynomial : ");
    no_points = getint();
    point = (pts *)malloc((no_points+1)*sizeof(pts));
    for(i=0;i<no_points;++i)
    {
        printf("enter the (x,y) of %d point : ",(i+1));
        scanf("%lf%lf",&point[i].x,&point[i].y);
    }
    point[i].x = point[0].x ;
    point[i].y = point[0].y ;

    register double area = 0 ;
   for(i=0;i<no_points;++i)
   {
         area += (point[i].x*point[i+1].y);
   }
   for(i=0;i<no_points;++i)
   {
         area -= (point[i].y*point[i+1].x);
   }
   if(area == 0) printf("area = 0.\nMeans vertexs are on one line\n");
   else if(area<0) printf("area = %lf .\n",(-1)*(area/2));
   else printf("area = %lf .\n",(area/2));
    return 0;
 }