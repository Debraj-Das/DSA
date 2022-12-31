#include <iostream>

using namespace std ;


int main()
 {
   string num ;
   cout<<"\nEnter any positive number :: ";
   cin>>num ;
   register int n = num.length();
   cout<<"\nReverse of a Number [ "<<num<<" ] is\n\t :: [ ";
   while ((--n)>(-1))
   {
    cout<<num[n];
   }
   cout<<" ]"<<endl ;
  
  return 0;
 }