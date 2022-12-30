
#include <stdio.h>

int power(register int a,register int b)
{
    register int val ;
    for(val=1;b;--b)
    val*=a;
    return val;
}

int main()
{
    int number ;
    printf("Enter the number :: ");
    scanf("%d",&number);
    // find the no of digit
    register int no_of_digit ,tum , new_number ;
    for(no_of_digit=0, tum = number ; tum ; ++no_of_digit)
        tum/=10 ;
    // find new number 
    for(new_number=0, tum = number;tum;tum/=10)
        new_number+=power((tum%10),no_of_digit);
    if(new_number==number)
    printf("%d is an armstrong number\n",number);
    else
    printf("%d is not an armstrong number\n",number);
    
    return 0;
}