#include <iostream>

using namespace std;

int main()
{
  long long int year;
  cout << "\nEnter any Year (XXXX) :: ";
  cin >> year;
  if (year % 100 == 0)
  {
    if (year % 400 == 0)
      cout << "\nThe Entered Year [ " << year << " ] is a Leap Year."<<endl ;
    else
      cout << "\nThe Entered Year [ " << year << " ] is NOT a Leap Year."<<endl ;
  }
  else
  {
    if (year % 4 == 0)
      cout << "\nThe Entered Year [ " << year << " ] is a Leap Year."<<endl ;
    else
      cout << "\nThe Entered Year [ " << year << " ] is NOT a Leap Year."<<endl ;
  }

  return 0;
}