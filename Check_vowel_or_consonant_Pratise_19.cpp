#include <iostream>

using namespace std;

int main()
{
  char ch;
  bool uppercase, lowercase;
  cout << "\nEnter any character to checck :: ";
  cin >> ch;
  uppercase = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
  lowercase = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  if (uppercase || lowercase)
    cout << "\nThe Entered Character [ " << ch << " ] is a vowel." << endl;
  else
    cout << "\nThe Entered Character [ " << ch << " ] is a Consonant." << endl;

  return 0;
}