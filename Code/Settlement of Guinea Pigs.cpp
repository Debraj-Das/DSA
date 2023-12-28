// Problem: B. Settlement of Guinea Pigs
// URL: https://codeforces.com/problemset/problem/1802/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

const char el = '\n';

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int __t, n, tot, m, x, ans;
   cin >> __t;
   while (__t--)
   {
      cin >> n;
      tot = 0, m = 0, ans = 0;
      while (n--)
      {
         cin >> x;
         if (x == 2)
         {
            ans = max(ans, 1 * (tot > 0) + tot / 2 + m);
            tot += m;
            m = 0;
         }
         else
            m++;
      }

      ans = max(ans, 1 * (tot > 0) + tot / 2 + m);
      cout << ans << el;
   }

   return 0;
}
