#include <iostream>

using namespace std ;

int factorial(int number )
{
  if(number<2) return 1 ;
  return number*factorial(number-1);
}


int main()
 {
  int num ;
  cout << "Enter the number for finding factorial :";
  cin>>num ;
  cout <<"\nfactorial of "<<num<<" is "<<factorial(num)<<endl ;
  
  return 0;
 }