#include <stdio.h>
#include <stdlib.h>

 union sum
 {
  int i ;
  float fo ;
  double it ;
  char pi ;
 };
 

int main()
 {
   union sum var ;
   printf("size of variable is %d.\n",sizeof(var));
   printf("Address of int %p\n",&(var.i));
   printf("Address of float %p\n",&(var.fo));
   printf("Address of double %p\n",&(var.it));
   printf("Address of char %p\n",&(var.pi));
   var.i = 65 ;
   printf("value of integer in union is %d\n",var.i);
   printf("value of float in union is %f\n",var.fo);
   printf("value of double in union is %lf\n",var.it);
   printf("value of char in union is %c\n",var.pi);

  return 0;
 }