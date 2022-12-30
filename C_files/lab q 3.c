#include <stdio.h>

int main()
{
    int w,x,y,z,a,b,c,d,i;
    float r;
    printf("Enter xmin and xmax of R:");
    scanf("%d %d",&w,&x);
    printf("Enter ymin and ymax of R:");
    scanf("%d %d",&y,&z);
    printf("Enter (x,y) of 1st endpoint of L:");
    scanf("%d %d",&a,&b);
    printf("Enter (x,y) of 2st endpoint of L:");
    scanf("%d %d",&c,&d);
   while(w<x) {
    r =(x-a)*((float)(d-b)/(c-a));
    if(r>=y&&r<=z) {
       i=0;
       break ;
    }
          ++w ;
   }
   if(i==0) printf("R contains L.");
   else  printf("R does not contains L.");
    return 0;
}
