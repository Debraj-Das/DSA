#include <stdio.h>
#include <stdlib.h>

int facbonaci_serious(register int n)  //* I do this problem by function for practise.
{
    register int previous = 1 , vaule = 1 ;
    for(register int i = 0 , tem ; i < n ; ++i)
    {
        previous += vaule ;
        tem = previous ;
        previous = vaule ;
        vaule = tem ;
    }
    return vaule ;
}

int main()
{
    int n ;
    printf("Enter the no of element :: ");
    scanf("%d",&n);
    printf("%d th member of fabinacy member is %d\n\n",n,facbonaci_serious(n-2));
    return 0;
}