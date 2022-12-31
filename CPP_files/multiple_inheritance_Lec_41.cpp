#include <iostream>

using namespace std;

class Base1
{
protected:
  int base1int;

public:
  void set_base1int(int a)
  {
    base1int = a;
    return;
  }
};

class Base2
{
protected:
  int base2int;

public:
  void set_base2int(int a)
  {
    base2int = a;
    return;
  }
};

class Drive : public Base1, public Base2
{
public:
  void show()
  {
    cout << "\nvalue of base1 is " << base1int << endl
         << "value of base2 is " << base2int << endl
         << "sum of base1 and base2 is " << (base1int + base2int) << endl;
  }
};

/*
  The ingerited derived class will lood something like this :
  Data members:
      base1int --> protected
      base2int --> protected
  Member functions:
      set_base1int() --> public    
      set_base2int() --> public  
      show()  --> public.
*/

int main()
{
  int x;
  Drive obj;
  cout << "Enter value of base1 ";
  cin >> x;
  obj.set_base1int(x);
  cout << "Enter value of base2 ";
  cin >> x;
  obj.set_base2int(x);
  obj.show();

  return 0;
}