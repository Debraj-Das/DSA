#include <iostream>

using namespace std;

int main()
{
  double a, b, c;
  cout << "\nEnter 1st number :: ";
  cin >> a;
  cout << "\nEnter 2nd number :: ";
  cin >> b;
  cout << "\nEnter 3rd number :: ";
  cin >> c;
  cout << "The SUM of 3 Numbers [ " << a << " + " << b << " + " << c << " ] = " << (a + b + c) << endl
       << endl;
  cout << "The AVERAGE of 3 Numbers [ " << a << " , " << b << " , " << c << " ] = " << (a + b + c) / 3 << endl;

  return 0;
}