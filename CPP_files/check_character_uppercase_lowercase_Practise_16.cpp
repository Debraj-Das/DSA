#include <iostream>

using namespace std;

int main()
{
  char ch;
  cout << "\nEnter any character to check :: ";
  cin >> ch;
  if (ch >= 'A' && ch <= 'Z')
    cout << "\n Entered Character [ " << ch << " ] is an UPPERCASE Character.\n";
  else if (ch >= 'a' && ch <= 'z')
    cout << "\n Entered Character [ " << ch << " ] is an LOWERCASE Character.\n";
  else if (ch >= '0' && ch <= '9')
    cout << "\n Entered Character [ " << ch << " ] is an DIGITE Character.\n";
  else
    cout << "\n Entered Character [ " << ch << " ] is an SPECIAL Character.\n";

  return 0;
}