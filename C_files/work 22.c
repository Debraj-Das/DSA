//Debraj Das
//Roll no-21CH30010
//reverse the digits of a number and to find the sum of the digit.
#include <stdio.h>

int main()
{
    int x,a,sum;
    printf("Enter the number:");
    scanf("%d",&x);
    printf("Reverse the digit of number:");
    for(sum=0;x!=0;x=x/10){
        a=x%10;
         sum=sum+a ;
        printf("%d",a);
    }
    printf("\nsum of digit of the number %d",sum);
    return 0;
}
