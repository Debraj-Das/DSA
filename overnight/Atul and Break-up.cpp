#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long int;

int main()
{
   int k = 2e9 + 1, t, ans = 0;
   vector<int> v;

   for (int i = 1, j; ans < k; i++)
   {
      t = 0;
      for (j = i; j; j /= 10)
         t++;
      ans += (i * t);

      v.push_back(ans);
   }

   cin >> t;
   while (t--)
   {
      scanf("%d", &k);
      if (k == 0)
         ans = 0;
      else
      {
         ans = distance(v.begin(), lower_bound(v.begin(), v.end(), k)) + 1;
      }

      printf("%d\n", ans);
   }

   return 0;
}