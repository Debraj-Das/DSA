// This program is my life first c++ program;

#include <iostream>

  using namespace std ;

int main()
 {  
   int varible = 8 ;
   register double double_variable = 8.2345 ;
   bool bool_type_variable = true ;
    cout<< "\nHello world\nvaule of int type variable : "<< varible <<"\nbool type variable vaule : "<<bool_type_variable<<"\n" ;
    cout << "register type variable : "<<double_variable <<"\n";
    cout << "size of bool type variable : "<<sizeof(bool_type_variable);
    return 0;
 }