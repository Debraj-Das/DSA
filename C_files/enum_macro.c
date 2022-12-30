#include <stdio.h>
#define value 2.525512154 ;  // macro define ;

enum boo{faule=25,true};  // only devine interal by name ;

int main()
{
  enum boo var = true ;
  long double xor = value ;
  printf("value of xor is %0.9lf\n",(double)xor);
  printf("vaule of var = %d\nsize of boo = %d\n",var,sizeof(faule));
  return 0;
}