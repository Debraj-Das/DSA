#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n , i ;
  long long int sum ;
  printf("Enter the number of integer :: ");
  scanf("%d",&n);
  // for(i=1,n=sum,sum=0;i<=n;++i)  //* it's O(n);
  // {
  //   sum += i ;
  // }
  
//* second algorithm for add n natural number. and improtance thing it's O(1);
 sum = (n*n +n)/2 ;
  printf("sum of those integer is %d\n",sum);
  return 0;
}