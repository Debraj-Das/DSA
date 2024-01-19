#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

// f(0,0) = 0
// f(3x,2y) = f(x,y)
// f(3x+1,2y) = f(x,y)+1
// f(3x+2,2y) = f(x,y)
// f(3x,2y+1) = f(x,y)+1
// f(3x+1,2y+1) = f(x,y)+2
// f(3x+2,2y+1) = f(x,y)+1

int rec(ll x, int y)
{
   if (x == 0 and y == 0)
      return 0;

   int ans = 0;
   if (x % 3 + y % 2 == 1 or (x % 3 == 2 and y % 2 == 1))
      ans = 1;
   else if (x % 3 == 1 and y % 2 == 1)
      ans = 2;

   return rec(x / 3, y / 2) + ans;
}

int main()
{

   int t;
   cin >> t;

   ll x, y;
   while (t--)
   {
      scanf("%lld%lld", &x, &y);
      printf("%d\n", rec(x, y));
   }

   return 0;
}
