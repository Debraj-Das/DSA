#include <iostream>

using namespace std;

class Number
{
  int a;

public:
  Number &setdata(int a)  //? '&' is refferce oprator.
  {
    this->a = a;  /// "this" keyword actuall a pointer.
    return *this; /// it store address of object for which this method is called.
  }
  void printdata()
  {
    cout << "The value of a is " << a << endl;
    return;
  }
};

int main()
{
  Number obj;
  obj.setdata(4).printdata();

  return 0;
}