#include <iostream>

using namespace std;

int main()
{
  int yard, feet, inch;
  cout << "Enter Inches to Convert :: ";
  cin >> inch;
  yard = (inch / 36);
  inch %= 36;
  feet = (inch / 12);
  inch %= 12;
  cout << "After Conversion from inches to feets, yards and inches :: " << endl
       << endl
       << "Yards = " << yard << endl
       << endl
       << "Feet = " << feet << endl
       << endl
       << "Inches = " << inch << endl;

  return 0;
}