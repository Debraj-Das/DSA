#include <iostream>

using namespace std;

int main()
{
  register int n;
  cout << "Enter the n :: ";
  cin >> n;
  // for (register int i = (n - 1); i; --i)   //* it's time complixity O(n);
  //   n += i;
  
  n = (n*n+n)/2 ;  //~ it's time complixity O(1);
  cout << "sum of n natural number is " << n << endl;
  return 0;
}