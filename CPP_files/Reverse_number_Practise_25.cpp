#include <iostream>

using namespace std;

int main()
{
  register long long int n;
  cout << "\nEnter any positive number :: ";
  cin >> n;
  cout << "\nReverse of a Number [ " << n << " ] is :: [ ";
  while (n)
  {
    cout << (n % 10);
    n /= 10;
  }
  cout << " ]" << endl;

  return 0;
}