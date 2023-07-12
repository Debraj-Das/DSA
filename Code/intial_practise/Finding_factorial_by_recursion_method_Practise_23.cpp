#include <iostream>

using namespace std;

long long int factorial(int n)
{
  if (n < 2)
    return 1;
  return n * factorial(n - 1);
}

int main()
{
  int n;
  do
  {
    cout << "\nEnter any positive number finding factorial\n\t:: ";
    cin >> n;
  } while (n < 0);
  cout << "\nFactorial of Number [ " << n << "! ] is :: " << factorial(n)<<endl;

  return 0;
}