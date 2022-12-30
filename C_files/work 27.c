//Name-Debraj Das
//Roll no-21CH30010
//computing up
to n-th terms and k-order of generalized Fibonacci sequence.

#include <stdio.h>

int main()
{
   int k,n,a[100],t,i,sum;
   printf("++ Enter order of Fibonacci Sequence: ");
   scanf("%d",&k);
   printf("++ Enter Initial/Base Terms (space-separated): ");
   for(n=0;n<k;++n)
    scanf("%d",&a[n]);
   printf("++ Enter Number of Terms in Sequence to View: ");
   scanf("%d",&n);
   printf("\n** The Fibonacci Sequence upto %d-th Terms:\n",n);
   for(t=0;t<k;++t)
   printf(" %d",a[t]);
   for(t=0;t<n-k;++t){
   for(i=0,sum=0;i<k;++i)
   sum =sum +a[i];
   printf(" %d",sum);
   a[t%k]=sum;         }
   printf("\n");
    return 0;
}
