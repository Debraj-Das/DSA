#include <stdio.h>

int main()
{

    int n,i,j,x;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(i=1,x=n;i<n+1;++i){
         for(j=1;j<2*n;++j){
             printf("%d ",x);
          if(i>j) --x;
          else if(i>(2*n-j-1)) ++x;
      }
      x=n;
      printf("\n") ;
      }
       for(i=n-1,x=n;i>0;--i){
         for(j=1;j<2*n;++j){
             printf("%d ",x);
          if(i>j) --x;
          else if(i>(2*n-j-1)) ++x;
      }
      x=n;
      printf("\n") ;
      }
    return 0;
}
