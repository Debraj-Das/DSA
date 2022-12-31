#include <iostream>

using namespace std ;


int main()
 {
  int dividend , divisor ;
  cout<<"Enter dividend :: ";
  cin>>dividend ;
  cout<<"\nEnter divisor :: ";
  cin>>divisor;
  cout<<"\nQuotient = "<<(dividend/divisor)<<endl ;
  cout<<"\nRemainder = "<<(dividend%divisor)<<endl ;
  
  return 0;
 }