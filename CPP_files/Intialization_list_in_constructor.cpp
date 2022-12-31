#include <iostream>

using namespace std;

/*
  syntex for intialization list in constructor :
  constructor(argument-list) : initilization-section
  {
    assignment + other code ;
  }
*/

class Test
{
  int a; //@ 'a' declear first then 'b'.so 'a' always first intiallized then 'b'.
  int b; //@ how order in  arranged  at intiallized time of constructor.
public:
  //  Test(int i,int j) : a(i) ,b(j)  //~ initilization-section
  // Test(int i , int j) : a(i) , b(i+j)  //* ok
  // Test(int i , int j) : a(i) , b(2*j)  //* ok
  // Test(int i , int j) : a(i) , b(a+j)  //* ok
  // Test(int i , int j) : a(i+b) , b(j)   //~ 'a' take garbage value of 'b' because untill that time b is not intiallized.
  // Test(int i , int j) : b(j) , a(i)     //* ok
  Test(int i, int j) : b(j), a(i + b) //! always first decleared variable intiallized first.
  {                                   //! mean here 'a' intially first,so 'a' take garbage value of 'b'.
    cout << "The value of a " << a << endl;
    cout << "The value of b " << b << endl;
  }
};

int main()
{
  Test obj(4, 6);

  return 0;
}