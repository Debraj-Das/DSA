#include <stdio.h>
#include <stdlib.h>

int collatz(int n)
{
    if(n==1) return 0;
    else if(n%2==1)  return 1+collatz(3*n+1);
    else return 1+collatz(n/2);
}

int main()
 {
    int n;
    printf("\nEnter the intially vaule of Collatz conjecture : ");
    scanf("%d",&n);
    printf("number the step of Collatz conjecture %d .\n",collatz(n));
    return 0;
 }