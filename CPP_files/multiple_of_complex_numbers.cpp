#include <iostream>

using namespace std;
class Complex
{
private:
  double real;
  double imaginary;

public:
  void set_data(double a, double b)
  {
    real = a;
    imaginary = b;
    return;
  }
  void print_data(string str)
  {
    cout << str << real << " + " << imaginary << "i\n";
    return;
  }

  friend void set_mul_data(Complex &, Complex);
};

void set_mul_data(Complex &op1, Complex op2)
{
  double real_part = op1.real ;
  op1.real = (real_part*op2.real-op1.imaginary*op2.imaginary) ;
  op1.imaginary = (real_part*op2.imaginary+op2.real*op1.imaginary);
  return;
}

int main()
{
  Complex *object;
  int no_complex;
  cout << "Enter the no of Complex number : ";
  cin >> no_complex;
  object = new Complex[no_complex];

  register int i = 0;
  for (double x, y; i < no_complex; ++i)
  {
    cout << endl;
    cout << (i + 1) << ".Complex number respectively(r & i) : ";
    cin >> x >> y;
    object[i].set_data(x, y);
    object[i].print_data("enter complex number is ");
  }

  for (i = 1; i < no_complex; ++i)
  {
    set_mul_data(object[0], object[i]);
  }
  cout << endl;
  object[0].print_data("mul of those Complex number is ");

  delete object;
  return 0;
}