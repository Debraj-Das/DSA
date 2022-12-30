#include <stdio.h>
#include <stdlib.h>

typedef struct       //* structure name complex in c languege with typedeg.
{
    double real ;
    double imaginary ;
} complex ;

void display(complex number[],int n);

int main()
{
    complex number[5] ;
    register int i ;
    printf("Enter the number in squence(real , imaginary) ::\n");
    for(i = 0 ; i<5 ; ++i)
    {
        printf("%d) ",(i+1));
        scanf("%lf%lf",&number[i].real,&number[i].imaginary);
    }
    printf("display the number ::\n");
    display(number,5) ;
    return 0;
}

void display(complex number[],int n)  //* This function display the given array.
{
    for(register int i = 0 ;i<n ; ++i)
      printf("%d) %0.2lf + %0.2lf*i\n",(i+1),number[i].real,number[i].imaginary);
    return ;
}
