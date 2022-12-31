#include <iostream>
using namespace std;

void gcd(int, int);

int main()
{
   int a, b;

   cout << "Enter 1st number :: ";
   cin >> a;
   cout << "\nEnter 2nd number :: ";
   cin >> b;

   gcd(a, b);

   return 0;
}

// function to calculate g.c.d
void gcd(int a, int b)
{
   int m, n;

   m = a;
   n = b;

   while (m != n)
   {
      if (m > n)
         m = m - n;
      else
         n = n - m;
   }

   cout << "\nH.C.F of [ " << a << " ] and [ " << b << " ] is :: " << m << "\n";
}