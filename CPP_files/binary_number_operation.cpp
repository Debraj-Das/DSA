#include <iostream>

using namespace std;

class Binary         // in class element are by default private.
{
private:
  string binary_number;
  void chake_binary();

public:
  void getstring(void);
  void ones_complimant(void);

  void printstring(void)
  {
    cout << "\t" << binary_number << endl;
    return;
  }
};

void Binary::chake_binary()               // "::" class resolution oprator.
{
  for (int i = 0; binary_number[i] != '\0'; ++i)
  {
    if (binary_number[i] != '0' && binary_number[i] != '1')
    {
      cout << "\nEnter binary number's format is wrong because of " << binary_number[i] << " present\n";
      exit(-1);
    }
  }
  return;
}
void Binary::getstring()
{
  cout << "Enter the binary number \n\t";
  cin >> binary_number;
  chake_binary();                             // nesting of member function.
  return;
}
void Binary::ones_complimant()
{
  for (int i = 0; binary_number[i] != '\0'; ++i)
  {
    if (binary_number[i] == '0')
      binary_number[i] = '1';
    else
      binary_number[i] = '0';
  }
  return;
}

int main()
{
  Binary num;
  num.getstring();
  num.ones_complimant();
  cout << "After one's complimant.\n";
  num.printstring();

  return 0;
}