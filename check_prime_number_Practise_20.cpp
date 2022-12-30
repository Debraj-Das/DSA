#include <iostream>
#include <cmath>
using namespace std;

long long int input()
{
  long long int num;
  cout << "\nEnter any number :: ";
  cin >> num;
  if (num < (-1))
    num *= (-1);
  else if ((num == 0) || (num == -1) || (num == 1))
  {
    cout << "\nThe entering number is not prime or nonprime number." << endl;
    exit(-1);
  }
  return num;
}

int main()
{
  const long long int num = input() ;
  const int root = sqrt(num);
  if ((num % 2) == 0)
  {
    cout << endl
         << num << " is a nonprime number " << endl;
    cout << "And this number is divided by 2 " << endl;
    exit(0);
  }
  else if (((long long int)root * root) == num)
  {
    cout << endl
         << num << " is a nonprime number " << endl;
    cout << "This number is a proper squrt of " << root << endl;
    exit(0);
  }
  else
  {
    for (register int i = 3; i < root; i += 2)
    {
      if (num % i == 0)
      {
        cout << endl
             << num << " is a nonprime number " << endl;
        cout << "And this number's smallest dividor is " << i << endl;
        exit(0);
      }
    }
  }
  cout << endl
       << num << " is a prime number " << endl;

  return 0;
}