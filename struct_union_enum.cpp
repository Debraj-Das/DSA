#include <iostream>

using namespace std ;

#define default_vaule 1.05
 
 enum var {var1 ,var2 = 9, var3 };

  struct inter
  {
    int value ;
    float flt ;
    double dopp ;
  }  ;
   
   union pace
   {
      int i;
      double p ;
   };
   

int main()
 {
  
  cout<<"vaule of default is "<<default_vaule<<endl ;
  cout << "size of struct is "<<sizeof(struct inter)<<endl ;
  cout <<"size of union is "<<sizeof(union pace )<<endl ;
  cout << "vaule of var3 is "<<var3<<endl ;
  cout <<"size of long double is "<<sizeof(long double)<<endl ;
  cout <<"size of char is "<<sizeof(char )<<endl ;
  return 0;
 }