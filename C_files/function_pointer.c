#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)  {return a+b;}
int mul(int a,int b)  {return a*b;}

int do_operation(int (*op)(int , int ),int x ,int y)
{
    return op(x,y);
}

int main()
 {
    int result = do_operation(add, 5 ,32);
    int result2 = do_operation(mul,2,3);
    int (*opertion[2])(int , int );
    opertion[0] = add ;
    opertion[1] = mul ;
    printf("result = %d\n",result);
    printf("result2 = %d\n",result2);
    printf("vaule of fuction pointer %d  mul %d\n",(*opertion[0])(5,6),(*opertion[1])(5,6));
    return 0;
 }