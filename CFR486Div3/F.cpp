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
const char sp = ' ';
const int inf = 1e9;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define setpr(x) cout << setprecision(x) << fixed
#define sz size()

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

using vb = vector<bool>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> using P = pair<T1, T2>;
template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

template <typename T> inline T exp(T a, int b)
{
   T x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   // int __t ; cin >> __t; while (__t--)
   solve();

   return 0;
}

inline void solve()
{
   int a, n, m;
   cin >> a >> n >> m;
   vi rain(a + 1);
   V<pii> umb(a + 1, mp(inf, -1));
   vi costs(m);

   for (int i = 0, l, r, j; i < n; ++i)
   {
      cin >> l >> r;
      for (j = l; j < r; ++j)
         rain[j] = 1;
   }

   for (int i = 0, x, p; i < m; ++i)
   {
      cin >> x >> p;
      costs[i] = p;
      umb[x] = min(umb[x], mp(p, i));
   }

   // here m is like not taking any umbrella
   V<vi> dp(a + 1, vi(m + 1, inf));
   dp[0][m] = 0;

   for (int i = 0, j; i < a; ++i)
      for (j = 0; j <= m; ++j)
      {
         if (dp[i][j] == inf)
            continue;

         if (rain[i] == 0)
            dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);

         if (j < m)
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[j]);

         if (umb[i].ff != inf)
            dp[i + 1][umb[i].ss] = min(dp[i + 1][umb[i].ss], dp[i][j] + umb[i].ff);
      }

   int ans = inf;
   for (int i = 0; i <= m; ++i)
      ans = min(ans, dp[a][i]);

   cout << eif(ans == inf, -1, ans) << endl;

   return;
}
