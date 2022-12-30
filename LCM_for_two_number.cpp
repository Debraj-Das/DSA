#include <iostream>
using namespace std;

void lcm(int, int);

int main()
{
  int a, b;

  cout << "Enter 1st number :: ";
  cin >> a;
  cout << "\nEnter 2nd number :: ";
  cin >> b;

  lcm(a, b);

  return 0;
}

// function to calculate l.c.m
void lcm(int a, int b)
{
  int m, n;

  m = a;
  n = b;

  while (m != n)
  {
    if (m < n)
    {
      m = m + a;
    }
    else
    {
      n = n + b;
    }
  }

  cout << "\nL.C.M of [ " << a << " ] and [ " << b << " ] is :: " << m << "\n";
}