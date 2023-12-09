// Problem: C - Vacation
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   ll n, a, b, c;
   cin >> n >> a >> b >> c;

   for (ll i = 1, x, y, z, d, e, f; i < n; i++)
   {
      cin >> d >> e >> f;
      x = max(b, c) + d;
      y = max(a, c) + e;
      z = max(a, b) + f;
      a = x, b = y, c = z;
   }

   cout << max({a, b, c});

   return 0;
}
