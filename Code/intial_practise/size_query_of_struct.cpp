#include <iostream>

using namespace std ;

struct size    // why size of user struct data type is not always same of all data type?
{                          // it is improtance query because it also show in c language.
  int i ;
  float fulid ;
  char ch[100] ;
  double p ;
};

int main()
 {
   size deb ;
   cout <<sizeof(deb)<<endl ;
   cout << sizeof(float)<<endl ;
  
  return 0;
 }