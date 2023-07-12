#include <iostream>

using namespace std ;

#define CUBE(x) (x*x*x)

int main()
 {
    double n  ;
    cout<<"\nEnter any positive number :: ";
    cin>>n ;
    cout<<"\nThe Cube of Entered Number [ "<<n<<" ] is :: "<<CUBE(n)<<endl;
  
  return 0;
 }