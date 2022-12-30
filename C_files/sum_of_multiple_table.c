#include <stdio.h>
#include <stdlib.h>

int main()
{
   int sum = 0 , n ;
   printf("Enter the number :: ");
   scanf("%d",&n);
   for(int i = 1 ; i<=10 ; ++i)
      sum += (n*i);
    printf("sum of %d table member :: %d.\n\n",n,sum);
    return 0;
}