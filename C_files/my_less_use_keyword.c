#include <stdio.h>
#include <stdlib.h>

#define size_of_array 9 

enum{ faule=-1 , true } ;   // value is increase after variable by one if you not assigned.

int main()
 {
   int n = 9 , arr[n];
   for(n=0;n<size_of_array ;++n)
   {
    arr[n] = n+1;
   }
   for(n=0;n<size_of_array ;++n)
   {
    printf("%d\n",arr[n]);
   }
   if(true==0) 
   {
    printf("understand & remmember of enum is right.\n");
    goto jump ;
   }
   printf("size of enum variable is %d\n",sizeof(true));  // size of enum is 4 for my system.
   jump : 
   printf("understanding & remmenber of goto is right.\n");
  return 0;
 }