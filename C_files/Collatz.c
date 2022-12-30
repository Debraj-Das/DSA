#include <stdio.h>
#include <stdlib.h>

void collatz(int n)
{
    static int step =0;
    for(int i=0;i<n;++i) 
    printf("-");
    printf("*(%d)\n |",n);
    if(n==1) 
    {
        printf("\nX axis\nTotal step in this Collatz conjecture is %d\n",step);
        return ;
    }
    ++step;
    if(n%2==1) collatz(3*n+1);
    else collatz(n/2);
    return ;
}

int main()
 {
    int n;
    printf("\nEnter the intially vaule of Collatz conjecture : ");
    scanf("%d",&n);
    printf("\n |");
    for(int i=0;i<47;++i)
     printf("__");
    printf("Y axis\n |");
    collatz(n);
    return 0;
 }