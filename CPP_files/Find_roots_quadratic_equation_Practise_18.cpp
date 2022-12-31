#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a, b, c, determind;
  cout << "\nEnter coefficcient a :: ";
  cin >> a;
  cout << "\nEnter coefficcient b :: ";
  cin >> b;
  cout << "\nEnter coefficcient c :: ";
  cin >> c;
  determind = ((b * b) - (4 * a * c));
  if (determind < 0)
  {
    cout << "\nRoots are imaginary and different." << endl;
    determind = sqrt(-determind);
    determind /= (2 * a);
    cout << "\n\tx1 = " << (-b / (2 * a)) << " + " << determind << "*i" << endl;
    cout << "\n\tx2 = " << (-b / (2 * a)) << " - " << determind << "*i" << endl;
  }
  else if (determind == 0)
  {
    cout << "\nRoots are real and same. " << endl;
    cout << "\n\tx1 = x2 = " << (-b / (2 * a)) << endl;
  }
  else
  {
    cout << "\nRoots are real and different." << endl;
    determind = sqrt(determind);
    determind /= (2 * a);
    cout << "\n\tx1 = " << ((-b / (2 * a)) + determind) << endl;
    cout << "\n\tx2 = " << ((-b / (2 * a)) - determind) << endl;
  }

  return 0;
}