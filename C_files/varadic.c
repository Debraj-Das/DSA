#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int maximum(int num_args,...)
{
   va_list args ;
   va_start(args,num_args);
   int max ,x ;
   for(int i =0;i<num_args;++i)
   {
      if(i==0) max = va_arg(args , int );
      else 
      {
         x = va_arg(args , int );
         if(max<x) max = x ;
      }
   }
   va_end(args) ;
   return max ;
}

int main()
 {
   int max ;
   max = maximum(5,56,-26,89,5,-1);
   printf("maximum number between number is %d\n",max);
   return 0;
 }