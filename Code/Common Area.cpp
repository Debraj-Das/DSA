// Problem: Y. Common Area
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/Y
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

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

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

inline ll solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int t;
   cin >> t;
   rep(i, 0, t)
   {
      cout << "Case #" << (i + 1) << ": " << solve() << el;
   }

   return 0;
}

ll solve()
{
   int n;
   cin >> n;

   int x1 = -inf, y1 = -inf, x2 = inf, y2 = inf, a, b, c, d;
   while (n--)
   {
      cin >> a >> b >> c >> d;
      if (a > c)
         swap(a, c);
      if (b > d)
         swap(b, d);

      x1 = max(x1, a);
      x2 = min(x2, c);
      y1 = max(y1, b);
      y2 = min(y2, d);
   }

   if (x2 <= x1 or y2 <= y1)
      return 0;

   return 1ll * (x2 - x1) * (y2 - y1);
}
