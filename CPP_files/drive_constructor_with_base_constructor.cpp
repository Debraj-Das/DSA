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
  Base() {} /// default constructor.
  Base(int a, int b)
  {
    data1 = a;
    data2 = b;
  }
};

class Drived : public Base
{
  int data3;

public:
  Drived(int a = 10, int b = 20, int c = 1) : Base(a, b) //! invovked drived constructor with assigned base constructor.
  {
    data3 = c;
    data3 *= (getdata1() * data2);
  }
  ~Drived() {} //@ destructor of drived class.
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
  Drived obj1;
  cout << "vaule of data1 = " << obj1.getdata1() << endl;
  cout << "vaule of data3 = " << obj1.getdata3() << endl
       << endl;

  obj1.assign_data1(47);
  obj1.data2 = 5;
  obj1.setdata3();
  cout << "\nvaule of data1 = " << obj1.getdata1() << endl;
  cout << "vaule of data3 = " << obj1.getdata3() << endl
       << endl;

  Drived obj2(42, 7);
  cout << "vaule of data1 = " << obj2.getdata1() << endl;
  cout << "vaule of data3 = " << obj2.getdata3() << endl
       << endl;

  obj2 = Drived(45, 5, 3); //@ Syntex of call a constructor. if you not give name of object then it not apply any object.
  cout << "vaule of data1 = " << obj2.getdata1() << endl;
  cout << "vaule of data3 = " << obj2.getdata3() << endl
       << endl;

  return 0;
}