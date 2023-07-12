#include <iostream>
#include <iomanip>

using namespace std ;

int main()
 {
   /* constant variable is variable which assign only decleartion time 
         other time it is a read only variable.

   const int a = 0 ;
   a = 5 ;   ** it give you error at complied time because a is a constant variable.
   cout<< a ;
                   */
    
    int i = 45 ;
    cout <<setw(3)<< i<<endl  ;   // endl and setw are two manipulators of c++ language.
                           // endl use of newline and setw use for left side fixed in formatting int number only.
                           // for setw manipulators include iomanip header file.
      
   return 0;
 }