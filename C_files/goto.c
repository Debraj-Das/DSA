#include <stdio.h>

int main()
 {
  int i ,num ;
  while(1)
  {
    for(i=0 ;i<10 ;++i)
    {
      printf("Enter the number.For exit enter 0 : ");
      scanf("%d",&num);
      if(num==0)
      goto end ;    // goto syntex.
    }
  }
   end:
  
  return 0;
 }

 /* goto statement most used for break nest loop by one codition.
    but it also used to travel one point another point of programme.
    But general told that for less used it beause it created confusing in unstanding 
    other programmer. */