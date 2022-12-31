#include <iostream>

using namespace std;

class Num
{
private:
  static int count;
  int vaule;

public:
  Num()
  {
    ++count;
    vaule = count;
    cout << "\nconstructer is invoked for " << vaule << " object.\n";
  }
  ~Num()
  {
    cout << "\ndestructor is invoked for " << vaule << " object.\n";   
  }
};

int Num::count = 0 ;  // static member has default vaule Zero(0)

int main()
{
   cout <<"called first object "<<endl;
   Num obj1 ;
   {
    cout<<"\nEntering first into block of statement."<<endl ;
    cout << "again call two object."<<endl ;
    Num obj2  ; 
    Num obj3 ;
    cout<<"\nexiting form block of statement."<<endl ;
   }
   cout <<"\nback to main "<<endl ;
   {
    cout<<"\nAgain Entering second block into block of statement."<<endl ;
    cout << "again call two object."<<endl ;
    Num obj4  ; 
    Num obj5 ;
    cout<<"\nexiting form block of statement."<<endl ;
   }
   cout <<"\nback to main "<<endl ;
  return 0;
}