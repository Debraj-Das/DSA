#include <iostream>

using namespace std;

class Base1
{
  int data1;

public:
  Base1(int a)
  {
    data1 = a;
    cout << "base 1 constructor is call" << endl;
  }
  void printdata1()
  {
    cout << "The vaule of data 1" << data1 << endl;
    return;
  }
};

class Base2
{
  int data2;

public:
  Base2(int a)
  {
    data2 = a;
    cout << "base 2 constructor is call" << endl;
  }
  void printdata2()
  {
    cout << "The vaule of data 1" << data2 << endl;
    return;
  }
};

class Drived : public Base1 , public Base2  //~ constructor call depend on order of base in decleration.
{
  int drive1, drive2;

public:
  Drived(int a, int b, int c, int d) : Base1(a), Base2(b)
  {
    cout<<"Drive constructor is call."<<endl ;
    drive1 = c;
    drive2 = d;
  }
  void printdatadrive()
  {
    printdata1();
    printdata2();
    cout << "The value of drive1 is " << drive1 << endl;
    cout << "The value of drive2 is " << drive2 << endl;
    return;
  }
};

int main()
{
  Drived obj(1, 2, 3, 4);
  obj.printdatadrive();

  return 0;
}