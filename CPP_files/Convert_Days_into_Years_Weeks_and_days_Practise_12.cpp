#include <iostream>

using namespace std;

int main()
{
  register int days;
  cout << "\nEnter No. of days :: ";
  cin >> days;
  cout << "\nNo. of Years :: " << (days / 365) << endl;
  days %= 365;
  cout << "No. of Weeks :: " << (days / 7) << endl;
  days %= 7;
  cout << "No. of Days :: " << days << endl;

  return 0;
}