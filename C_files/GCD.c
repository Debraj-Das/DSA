#include <stdio.h>
#include <stdlib.h>

int main()
 {   
    int a,b,tum;
    do 
    {
    printf("\nEnter the a and b respectively : ");
    scanf("%d%d",&a,&b);
    if(a<0)
          a*=(-1);
     if(b<0)     
          b*=(-1);
    if(a<b)
    {
       tum=a;
       a=b;
       b=tum;
    }
    while(b!=0)
    {
       tum=a%b;
       a=b;
       b=tum;
    }
    printf("\nGCD of the a and b is %d.\n",a);
    printf("\nIf you continue your computation than Enter the any nonZero number or not than Enter Zero.\n");
    printf("\tFor again computation Enter your input : ");
    scanf("%d",&tum);
    }
    while(tum);
    printf("\n\n Computation is finished.\n");
    return 0;
 }