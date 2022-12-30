/*Name-Debraj das
Roll no-21CH30010
question-convert decimal number into binary number & trinary number.
 */

#include <stdio.h>

int main()
{
    int n,m,i,a[32];
    printf("convert decimal number into other number system enter the Decimal number.\n ");
    printf("If you Want to terminated the program enter the zero(0)\nBecause all number system zero is always 0.");
    while(1)
    {
        printf("\nEnter the Decimal number ");
        scanf("%d",&n);
        if(n==0) break ;
        printf("Which number system? write the number :");
        scanf("%d",&m);
        printf(" Number of that number system of Decimal number :");
        for(i=0; n!=0; ++i)
        {
            a[i]=n%m;
            n=n/m;
        }
        while(i!=0)
        {
            printf("%d",a[--i]);
        }
    }
    return 0 ;
}
