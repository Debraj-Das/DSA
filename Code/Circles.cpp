// Problem: W. Circles
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/W
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

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   // int __t ; cin >> __t; while (__t--)
   solve();

   return 0;
}

template <class T> inline double dist(T a, T b)
{
   double x = (a.ff - b.ff);
   double y = (a.ss - b.ss);
   return sqrt(x * x + y * y);
}

void solve()
{
   pii point[4];
   rep(i, 0, 4) cin >> point[i].ff >> point[i].ss;

   P<double, double> c1, c2;

   c1.ff = (point[0].ff + point[1].ff) / 2.0;
   c1.ss = (point[0].ss + point[1].ss) / 2.0;

   c2.ff = (point[2].ff + point[3].ff) / 2.0;
   c2.ss = (point[2].ss + point[3].ss) / 2.0;

   double dt = dist(c1, c2), r1 = dist(point[0], point[1]) / 2.0, r2 = dist(point[2], point[3]) / 2.0;

   cout << eif(dt <= r1 + r2, "YES", "NO");

   return;
}
