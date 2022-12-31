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

  void set_sum_data(Complex, Complex);
};

void Complex::set_sum_data(Complex op1, Complex op2)
{
  real = op1.real + op2.real;
  imaginary = op1.imaginary + op2.imaginary;
  return;
}

int main()
{
  Complex *object, sum;
  int no_complex;
  cout << "Enter the no of Complex number(atleast two) : ";
  cin >> no_complex;
  object = new Complex[no_complex];

  register int i = 0;
  for (double x, y; i < no_complex; ++i)
  {
    cout << endl;
    cout << "Enter the " << (i + 1) << " complex number(x + iy) respectively(x & y) : ";
    cin >> x >> y;
    object[i].set_data(x, y);
    object[i].print_data("enter complex number is ");
  }

  sum.set_sum_data(object[0], object[1]);
  for (i = 2; i < no_complex; ++i)
  {
    sum.set_sum_data(sum, object[i]);
  }
  cout << endl;
  sum.print_data("Sum of those Complex number is ");

  delete object;
  return 0;
}