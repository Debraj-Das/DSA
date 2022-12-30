//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>
int check(int a[],int i)
{
    int p,q=0;
    float m1,m2,c1,c2,x,y,n;
    m1=(a[i+1]-a[i+3])/(a[i]-a[i+2]);
    c1=a[i+1]-m1*a[i];
    for(p=0;p<i-1;p+=2){
     m2=(a[p+1]-a[p+3])/(a[p]-a[p+2]);
    c2=a[p+1]-m1*a[p];
   if(m1!=m2) {x=(c2-c1)/(m2-m1);
      n=(a[i]-x)/(x-a[i+2]);
      if(n>0) ++q;}

    }
    return q;
}
int main()
{
    int a[800],i,z,n;
    printf("How many vertices? ");
    scanf("%d",&n);
    printf("Enter X and Y co-ordinates: \n");
    for(i=0;i<2*n;i+=2)
    scanf("%d %d\n",&a[i],&a[i+1]);
    a[2*n]=a[0];
    a[2*n+1]=a[1];
    for(i=0;i<2*n+1;i+=2)
        z=check(a,i);

        if(z==0) printf("Polygon is a simple polygon.");
        else {
            printf("Polygon is a not simple polygon.\nNumber of intersecting pairs of non-adjacent sides is %d",z);
        }
    return 0;
}
