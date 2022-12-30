#include <stdio.h>
#include <stdlib.h>

int gobal ;
 
void func();

int main()
 {
  int  a , b[5] , *c ;
  c = (int *)malloc(2*sizeof(int ));
  printf("address of auto simple variable : %p\n",&a); 
   printf("address of static array  variable : %p\n",b);
    printf("address of dynamic array variable : %p\n",c);
  func();
  printf("address of gobal variable : %p\n",&gobal);
  printf("address of main : %p\n",main);
  printf("address of function variable : %p\n",func);
  free(c);
  return 0;
 }

void func()
{
  static int st_var = 0 ;
  int fuc_var = 0 ;
  int *dy ;
  dy = (int *)malloc(2*sizeof(int ));
  printf("address of dynamic array variable in function : %p\n",dy);
  printf("address of auto simple variable in function : %p\n",&fuc_var);
  printf("address of static simple variable : %p\n",&st_var);
  free(dy);
  return ;
}