#include <stdio.h>
#include <stdlib.h>

int main()
 {
    long long int t[3],tum; // declearing the varible.
     int n , i;
    for(i=0;i<3;++i)  // intiated the variable.
   {
       t[i]=i;
   }
  while(1)
  {
   do {
   printf("Enter the positive integer number you want to see : ");
   scanf("%d",&n);
   if(n==0) break;
   if(n<0)  printf("you enter the nagative number so again ");
   }
   while(n<0);

   if(n<3)  
   {
      printf("\n %dth number is %lld.\n",n,t[n]);
      return 0;
   }
   
   for(i=3;i<n;++i)    // computed the term.
   {
      tum=3*t[2]*t[1]-2*t[1]*t[0]+1;
      t[0]=t[1];
      t[1]=t[2];
      t[2]=tum;
   }
   
    printf("\n %dth number is %lld.\n",n,tum);
    printf("\n Computation again start. if you want to exit form computation enter Zero.\n\nAgain ");
  }
    return 0;
 }