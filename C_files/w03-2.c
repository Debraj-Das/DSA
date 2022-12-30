#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,x,y,l,n;
    double m;
    printf("Enter (x,y) coordinates of Point p: ");
    scanf("%d%d",&a,&b);
     printf("Enter (x,y) coordinates of Point q: ");
    scanf("%d%d",&x,&y);
    if(x<a)  {
        l=a; a=x; x=l;
        n=b; b=y; y=n;
    }
    if(x==a) {
        n=1; l=0;
        y=y-b;
    }
     else {
            m=(double)(y-b)/(x-a);
    for(l=1;l<=x-a;++l) {
        n=l*m;
        if(n==l*m) break ;
    }
    if(l>=x-a) {   n=y-b;  l=x-a;  }
    y=(x-a)/l+1;
     }
    printf("Number of integer points on the line segment pq : %d.\n",y);
    printf("Integer points on the line segment pq: \n");
    for(x=1;x<=y;++x){
        printf("%d :(%d,%d)\n",x,a,b);
     a+=l;
     b+=n;
    }

    return 0;
}
