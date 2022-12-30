#include <iostream>

using namespace std;

int main()
{
  int n, i;
  cout << "\nEnter any positive number :: ";
  cin >> n;
  cout << "\nMultiplication Table of a given number [ " << n << " ] ::\n\n";
  for (i = 1; i < 11; ++i)
  {
    cout << "\t" << n << " * " << i << " = " << (n * i) << endl
         << endl;
  }
  cout << "Multiplication Table finished." << endl;
  return 0;
}