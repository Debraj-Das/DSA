#include <iostream>

using namespace std;

#define el '\n'

int main()
{
   const int n = 0 ;

    // int *p = &n ; // it give error because n is const and p is not const pointer

    const int *p = &n ; // it is const data type pointer not const pointer

    cout<<*p<<el;

    // But it can change the address of it pointing

    const int n1 = 112 ;
    p = &n1 ;

    cout<<*p<<el;

    // int * const p1 = &n ; // it is const pointer not const data type pointer (so it give error)

    int t = 10 ;

    int * const p1 = &t ; // it is const pointer so it can't change it's address

    cout<<*p1<<el;

    // int t1 = 20 ;
    // p1 = &t1 ; // it give error because p1 is const pointer


    // const pointer with const data type

    const int * const p2 = &t ; // it is const pointer with const data type

    cout<<*p2<<el; 

    
    
    return 0;
}