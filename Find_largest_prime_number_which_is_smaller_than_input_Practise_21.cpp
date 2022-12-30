#include <iostream>
#include <cmath>
using namespace std;

long long int input()
{
  long long int num;
  cout << "\nEnter any positive number finding smaller prime number but greaterest :\n\t:: ";
  cin >> num;
  if ((num == 0) || (num <= -1) || (num == 1))
  {
    cout << "\nThe entering number is not prime or nonprime number." << endl;
    exit(-1);
  }
  if ((num % 2) == 0)
  {
    num--;
  }
  return num;
}

int main()
{
  register int root, i;
  register long long int num = input();
  while (num > 1)
  {
    root = sqrt(num);
    for (i = 3; i <= root; i += 2)
    {
      if (num % i == 0)
      {
        i = 0;
        break;
      }
    }
    if (i)
    {
      cout << "largest prime number which is smaller than input is " << num << endl;
      exit(0);
    }
    else
      num -= 2;
  }
  cout << "There are no prime number" << endl;
  return 0;
}