#include <iostream>

using namespace std;

class Number
{
  int a;

public:
  void display()
  {
    cout << "number of this object is " << a << endl;
    return;
  }
  Number() {}    //* blank construct for fexiblity of programming.
  Number(int n)
  {
    a = n ;
  }
  Number(Number &ob)   //# copy construct . If any one no creat copy construct than compliler supply.
  {
    cout << "copy construct is invoved!!"<<endl ;
    a = ob.a;
  }
};

int main()
{ 
  Number x(5) , co ;   // for x second construct invoveked but for co blanks construct invoveked.
  x.display();
  Number y(x);         // for y copy construct invoveked.
  y.display();
  Number z = y ;       // for z copy construct invoveked. because decleartion with assigned the objeced.
  z.display();
  co = z ;             // for co copy construct not  invoveked.only assigned one object to another like structure.
  co.display();

  return 0;
}