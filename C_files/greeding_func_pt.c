#include <stdio.h>
#include <stdlib.h>

typedef void (*fpointer )() ;

void afternoongreed()
{
  printf("good afternoon user.\n");
  return ;
}

void eveninggreed()
{
  printf("good evening user.\n");
  return ;
}

 void average(fpointer fp , double a ,double b)
 {
    fp();
    printf("average of %lf and %lf is %lf.\n\n",a,b,(a+b)/2);
   return ;
 }


int main()
 {
    double num1 ,num2 ;
    printf("Enter two number for average : ");
    scanf("%lf%lf",&num1,&num2);
    average(eveninggreed,num1,num2);
    average(afternoongreed,num1,num2);
  
  return 0;
 }