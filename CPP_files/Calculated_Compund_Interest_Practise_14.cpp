#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double principle, rate_of_interest, period;
  cout << "\nEnter Principle (Amount) :: ";
  cin >> principle;
  cout << "\nEnter Rate of Interest :: ";
  cin >> rate_of_interest;
  cout << "\nEnter Time Period :: ";
  cin >> period;
  cout << "\nThe Calculated Compound Interest is = "
       << (principle * pow((1 + rate_of_interest / 100), period)) << endl;

  return 0;
}