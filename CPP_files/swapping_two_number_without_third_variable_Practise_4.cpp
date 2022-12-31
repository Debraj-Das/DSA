#include <iostream>

using namespace std ;


int main()
 {
   double a , b ;
   cout<<"Enter 1st number :: ";
   cin>>a ;
   cout<<"\nEnter 2nd number :: ";
   cin>>b ;
   cout<<"\nBefore swapping, Numbers are ::  "<<endl<<"\na = "<<a<<", b = "<<b<<endl ;
   a+=b ;
   b = (a-b);
   a-=b;
   cout<<"\nAfter swapping, Number are :: "<<endl<<"\na = "<<a<<", b = "<<b<<endl ;
  
  return 0;
 }