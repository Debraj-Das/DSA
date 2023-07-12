#include <iostream>

using namespace std;

int main()
{
  long long int n;
  cout << "\nEnter any positive integer\n\t::";
  cin >> n;
  register long long chance = n;
  register int i = 0;
  while (chance)
  {
    chance /= 10;
    ++i;
  }
  cout << "\nNumber of Digits in a number [ " << n << " ] is :: " << i << endl;
  return 0;
}