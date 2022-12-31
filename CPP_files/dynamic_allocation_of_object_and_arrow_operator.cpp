#include <iostream>

using namespace std;

class Complex
{
  int real;
  int imaginary;

public:
  void setdata(int a, int b)
  {
    real = a;
    imaginary = b;
    return;
  }
  void printdata()
  {
    cout << "The number is " << real << " + " << imaginary << " i " << endl;
    return;
  }
  Complex(int a = 5, int b = 10) : real(a), imaginary(b)
  {
    cout << "construct is called." << endl;
  }
};

int main()
{
  Complex *ptobj;
  ptobj = new Complex(1, 1);
  ptobj->printdata();
  ptobj->setdata(45, 52);
  ptobj->printdata();
  delete ptobj;
  Complex *ptobj1 = new Complex;
  ptobj1->printdata();
  delete ptobj1;

  ptobj1 = new Complex[40];
  for (int i = 0; i < 40; ++i)
  {
    ptobj1[i].setdata(5 * i, 2 * i);
  }
  for (int i = 0; i < 40; ++i)
  {
    ptobj1[i].printdata();
  }
  delete[] ptobj1;
  return 0;
}