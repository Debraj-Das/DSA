#include <iostream>

using namespace std;

int input()
{
  int num;
  do
  {
    cout << "\nEnter any positive number for finding it factorial\n\t::";
    cin >> num;
  } while (num < 0);

  return num;
}

int main()
{
  register int i;
  const int n = input();
  if (n == 0)
  {
    cout << "\nFactorial of Number [ 0! ] is :: 1\n";
  }
  else if (n <= 12)
  {
    register long long int factorial;
    for (i = 1, factorial = 1; i <= n; ++i)
      factorial *= i;
    cout << "\nFactoial of Number [ " << n << "! ] is :: " << factorial << endl;
  }
  else
  {
    register long double factorial;
    register int pow;
    for (i = 1, factorial = 1, pow = 0; i <= n; ++i)
    {
      factorial *= i;
      if (factorial > (1000))
      {
        factorial /= 1000;
        pow += 3;
      }
    }
    cout << "\nFactoial of Number [ " << n << "! ] is :: "
         << factorial << "EXP(" << pow << ")" << endl;
  }
  return 0;
}