#include <iostream>

using namespace std;

int main()
{
  register double x, vaule;
  register int n, i;
  cout << "\nEnter value of X :: ";
  cin >> x;             //* cin function not take address of x . so register varible can be used.
  cout << "\nEnter value of N :: ";
  cin >> n;
  for (i = 0, vaule = 1; i < n; ++i)
    vaule *= x;
  cout << "\nThe Power of Number [ " << x << " ^ " << n << " ] = " << vaule << endl;
  return 0;
}