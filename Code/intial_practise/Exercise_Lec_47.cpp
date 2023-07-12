#include <iostream>
#include <cmath>

using namespace std;

class Simplecalculator
{
  double a, b;

public:
  void getsimpledata()
  {
    cout << "\nEnter the vaule of a ";
    cin >> a;
    cout << "Enter the vaule of b ";
    cin >> b;
    cout << endl;
    return;
  }
  void performancesimplecalculation()
  {
    cout << "The value of a + b = " << (a + b) << endl;
    cout << "The value of a - b = " << (a - b) << endl;
    cout << "The value of a * b = " << (a * b) << endl;
    cout << "The value of a / b = " << (a / b) << endl;
    return;
  }
};
class Scientificcalculator
{
  double var;

public:
  void getscientificdata()
  {
    cout << "\nEnter the value of a ";
    cin >> var;
    cout << endl;
    return;
  }
  void performancescientificcalculation()
  {
    cout << "The value of sin(" << var << ") = " << sin(var) << endl;
    cout << "The value of tan(" << var << ") = " << tan(var) << endl;
    cout << "The value of exp(" << var << ") = " << exp(var) << endl;
    cout << "The value of log(" << var << ") = " << log(var) << endl;

    return;
  }
};

class Hydridcalculator : public Simplecalculator, public Scientificcalculator
{
  
};

int main()
{
  Hydridcalculator obj;
  obj.getsimpledata();
  obj.performancesimplecalculation();
  obj.getscientificdata();
  obj.performancescientificcalculation();
  return 0;
}