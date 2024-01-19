#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int t, n, k, bh[1001], gh[1001], i;
   scanf("%d", &t);
   long long ans;
   while (t--)
   {
      scanf("%d%d", &n, &k);
      for (i = 0; i < n; i++)
         scanf("%d", &bh[i]);
      for (i = 0; i < n; i++)
         scanf("%d", &gh[i]);
      sort(bh, bh + n);
      sort(gh, gh + n, greater<int>());

      ans = 0;
      for (i = 0; i < n and ans < k; i++)
      {
         ans += (bh[i] * gh[i]);
      }

      if (ans > k)
         printf("NO\n");
      else
         printf("YES\n");
   }
   return 0;
}
