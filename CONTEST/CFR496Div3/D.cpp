// Problem: D. Polycarp and Div 3
// URL: https://codeforces.com/contest/1005/problem/D
/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   string s;
   cin >> s;

   const int n = s.sz;
   int f[] = {0, -1, -1};
   int z[n + 1] = {0};
	
	for(int i = 0 , x = 0 ; i < n ; i++)
   {
      x = (x + s[i] - '0') % 3;
      z[i + 1] = max(z[i], (f[x] != -1 ? z[f[x]] + 1 : 0));
      f[x] = i + 1;
   }

   cout << z[n];

   return 0;
}
