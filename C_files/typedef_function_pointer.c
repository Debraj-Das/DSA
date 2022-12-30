#include <stdio.h>
#include <stdlib.h>

typedef int (*opertion_ptr)(int ,int );  // typedef of function pointer.

int add(int a,int b)  {return a+b;}
int mul(int a,int b)  {return a*b;}

int do_operation(opertion_ptr op,int x ,int y)
{
    return op(x,y);
}

int main()
 {
    opertion_ptr opration = add;
    printf("add 1+5 = %d\n",opration(1,5));
    printf("address of add function %p \n",add);   
    opration = mul ;
    printf("mul 1*5 = %d\n",opration(1,5));
    printf("mul 12*5 = %d\n",do_operation(mul,12,5));  
    printf("add 12+5 = %d\n",do_operation(add,12,5));
    
    opertion_ptr f[2];
    f[0] = mul ;
    f[1] = add ;
    printf("mul 12*5 = %d\n",do_operation(f[0],12,5));  
    printf("add 12+5 = %d\n",do_operation(f[1],12,5));

    return 0;
 }

   /* Name of function is actuall address of the funtion in ram when it store in 
     ram of execution prepose . use the we define and typedef the function pointer 
     and also we defined array of the functon pointer by which we use many function 
     very easy way.*/