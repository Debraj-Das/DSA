#include <iostream>

using namespace std;

template <class type1, class type2>
class Myclass
{
  type1 data1;
  type2 data2;

public:
  Myclass(type1 a, type2 b)
  {
    data1 = a;
    data2 = b;
  }
  void display()
  {
    cout << "\tdata1 = " << data1 << ", data2 = " << data2 << endl;
    return;
  }
  ~Myclass() {  }
};

int main()
{
  cout << "1. int , int 2. int double 3.int char 4. int string" << endl
       << "5.double double  6. double char 7.double string  " << endl
       << "8. char char 9.char string " << endl
       << "10. string string and for exit enter Zero(0)." << endl;

  int i;
  while (true)
  {
    cout << "Enter the option number : ";
    cin >> i;
    switch (i)
    {
    case 0:
    {
      cout << "\nComputation is finished\n";
      goto jump;
    }
    case 1:
    {
      int a;
      int b;
      cout << "Enter the value of a(int ) ,b(int ) respectively : ";
      cin >> a >> b;
      Myclass<int, int> obj(a, b);
      obj.display();
      break;
    }
    case 2:
    {
      int a;
      double b;
      cout << "Enter the value of a(int ) ,b(double ) respectively : ";
      cin >> a >> b;
      Myclass<int, double> obj(a, b);
      obj.display();
      break;
    }
    case 3:
    {
      int a;
      char b;
      cout << "Enter the value of a(int ) ,b(char ) respectively : ";
      cin >> a >> b;
      Myclass<int, char> obj(a, b);
      obj.display();
      break;
    }
    case 4:
    {
      int a;
      string b;
      cout << "Enter the value of a(int ) ,b(string ) respectively : ";
      cin >> a >> b;
      Myclass<int, string> obj(a, b);
      obj.display();
      break;
    }
    case 5:
    {
      double a;
      double b;
      cout << "Enter the value of a(double ) ,b(double ) respectively : ";
      cin >> a >> b;
      Myclass<double, double> obj(a, b);
      obj.display();
      break;
    }
    case 6:
    {
      double a;
      char b;
      cout << "Enter the value of a(double ) ,b(char ) respectively : ";
      cin >> a >> b;
      Myclass<double, char> obj(a, b);
      obj.display();
      break;
    }
    case 7:
    {
      double a;
      string b;
      cout << "Enter the value of a(double ) ,b(string ) respectively : ";
      cin >> a >> b;
      Myclass<double, string> obj(a, b);
      obj.display();
      break;
    }
    case 8:
    {
      char a;
      char b;
      cout << "Enter the value of a(char ) ,b(char ) respectively : ";
      cin >> a >> b;
      Myclass<char, char> obj(a, b);
      obj.display();
      break;
    }
    case 9:
    {
      char a;
      string b;
      cout << "Enter the value of a(char ) ,b(string ) respectively : ";
      cin >> a >> b;
      Myclass<char, string> obj(a, b);
      obj.display();
      break;
    }
    case 10:
    {
      string a;
      string b;
      cout << "Enter the value of a(string ) ,b(string ) respectively : ";
      cin >> a >> b;
      Myclass<string, string> obj(a, b);
      obj.display();
      break;
    }
    default:
    {
      cout << "YOU enter wrong input.\n";
    }
    }
    cout << "Again Process start.\n\n";
  }
jump:
  return 0;
}