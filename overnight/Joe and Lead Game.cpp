#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

int main()
{
   int n;
   scanf("%d", &n);

   bool num[100005] = {false};
   int a[n], N = n;

   rep(i, 0, n)
   {
      scanf("%d", &a[i]);
      num[a[i]] = 1;
   }

   sort(a, a + n);
   n = unique(a, a + n) - a;

   int maxdiff = a[n - 1] - a[0];
   int mindiff = a[1] - a[0];

   rep(i, 2, n) mindiff = min(mindiff, a[i] - a[i - 1]);

   int cnt = (N != n), x;
   rep(i, mindiff, maxdiff + 1)
   {
      rep(j, 0, n)
      {
         x = a[j] + i;
         if (x > a[n - 1])
            break;

         if (num[x])
         {
            cnt++;
            break;
         }
      }
   }
   printf("%d\n", cnt);
   return 0;
}
