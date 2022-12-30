//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int seed,i,y,n,a[800],s,t,z;
   printf("Enter number of points: ");
   scanf("%d",&n);
  printf("Enter seed: ");
  scanf("%d",&seed);
  srand(seed);
  printf("Unique points generated: \n");
  for(i=0;i<n;s=0,t=0){
         s=rand()%21;
        t=rand()%21;
          y=1;
        for(z=0;z<2*i;z+=2)   {

  if(s+t==a[2*z]+a[2*z+1]){
    y =0;
    break;
  } }
  if(y!=0) {
  a[2*i]=s;
  a[2*i+1]=t;
  i++;}
       }
    for(i=0; i<2*n; i+=2)
    printf("%2d %2d\n",a[i],a[i+1]);
    return 0;
}
