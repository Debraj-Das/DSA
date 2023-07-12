#include <iostream>

using namespace std;

class Complex;

class Calculation
{
public:
  void set_sum_data(Complex &, Complex);
  void set_mul_data(Complex &, Complex);
};

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

  // friend void Calculation::set_mul_data(Complex &, Complex);  //gives access one by one friend.
  // friend void Calculation::set_sum_data(Complex &, Complex);
  friend class Calculation; // otherwish decleared friend with Calculation.
};

void Calculation::set_sum_data(Complex &op1, Complex op2)
{
  op1.real += op2.real;
  op1.imaginary += op2.imaginary;
  return;
}

void Calculation::set_mul_data(Complex &op1, Complex op2)
{
  double real_part = op1.real;
  op1.real = (real_part * op2.real - op1.imaginary * op2.imaginary);
  op1.imaginary = (real_part * op2.imaginary + op2.real * op1.imaginary);
  return;
}

int main()
{
  Complex value, *object;
  int no_complex;
  register int i = 0;
  Calculation opration;

  while (true)
  {
    cout << "Enter the no of Complex number : ";
    cin >> no_complex;
    if (no_complex == 0)
      break;

    object = new Complex[no_complex];
     i = 0 ;
    for (double x, y; i < no_complex; ++i)
    {
      cout << endl;
      cout << (i + 1) << ".Complex number respectively(r & i) : ";
      cin >> x >> y;
      object[i].set_data(x, y);
      object[i].print_data("enter complex number is ");
    }

    for (i = 0, value.set_data(0, 0); i < no_complex; ++i)
    {
      opration.set_sum_data(value, object[i]);
    }
    cout << endl;
    value.print_data("Sum of those Complex number is ");

    for (i = 0, value.set_data(1, 0); i < no_complex; ++i)
    {
      opration.set_mul_data(value, object[i]);
    }
    cout << endl;
    value.print_data("mul of those Complex number is ");

    delete object;
    cout << "\nNext Computation start.If you want to exit enter Zero(0)\n";
  }
  cout << "\n Computation process is finished.\n";
  return 0;
}