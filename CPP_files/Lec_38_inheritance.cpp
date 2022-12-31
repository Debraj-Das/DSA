#include <iostream>

using namespace std;

class Base
{
  int data1;

public:
  int data2;
  int getdata1()
  {
    return data1;
  }
  void assign_data1(int a)
  {
    data1 = a;
    return;
  }
  Base(int a = 10, int b = 20)
  {
    data1 = a;
    data2 = b;
  }
};

class Drived : public Base
{
  int data3;

public:
  Drived(int a = 10, int b = 20)
  {
    // Base(a, b);  //! construtor of Base class not used as assigned vaule by this sytex.it has different syntex.
    assign_data1(a);
    data2 = b ;
    data3 = getdata1() * data2;
  }
  int getdata3()
  {
    return data3;
  }
  void setdata3()
  {
    data3 = data2 * getdata1();
    return;
  }
};

int main()
{
  Drived obj1(56, 5);
  cout << "vaule of data1 = " << obj1.getdata1() << endl;
  cout << "vaule of data3 = " << obj1.getdata3() << endl;

  obj1.assign_data1(42);
  obj1.data2 = 5;
  obj1.setdata3();
  cout << "\nvaule of data1 = " << obj1.getdata1() << endl;
  cout << "vaule of data3 = " << obj1.getdata3() << endl;
  return 0;
}