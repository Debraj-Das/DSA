#include <iostream>

using namespace std;

class Emplee
{
private:
  int salary;
  static int count;

public:
  void gets_salery();
  void print();
  static void pcount();
};
int Emplee::count = 0; // defalute value of static variable has 0 value.

void Emplee::gets_salery()
{
  cout << "Enter the salery of emplee ";
  cin >> salary;
  cout << endl;
  ++count;
  return;
}

void Emplee::print()
{
  cout << "salery of emplee " << salary << endl;
  return;
}

void Emplee::pcount()
{
  cout << "no of emplee is " << (count + 1) << endl;
  return;
}

int main()
{
  Emplee deb, raj, das;

  Emplee::pcount(); // calling of static function .
  deb.gets_salery();

  Emplee::pcount();
  raj.gets_salery();

  Emplee::pcount();
  das.gets_salery();

  cout << endl;

  deb.print();
  raj.print();
  das.print();

  return 0;
}