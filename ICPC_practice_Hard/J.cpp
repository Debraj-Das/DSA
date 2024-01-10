// Problem: J. Help Vasilisa the Wise 2
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/J
// Memory Limit: 256 MB
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

   int testcase = 1;
   // cin >> testcase;
   while (testcase--)
   {
      solve();
   }

   return 0;
}

void solve()
{
   pii row, col, dia;
   cin >> row.ff >> row.ss;
   cin >> col.ff >> col.ss;
   cin >> dia.ff >> dia.ss;

   if (row.ff + row.ss != col.ff + col.ss or row.ff + row.ss != dia.ff + dia.ss)
   {
      cout << (-1);
      return;
   }

   int a, b, c, d;

   b = (dia.ss + row.ff - col.ff) / 2;
   c = (dia.ss - row.ff + col.ff) / 2;

   a = row.ff - b;
   d = row.ss - c;

   if (a > 9 or a < 1 or b > 9 or b < 1 or c > 9 or c < 1 or d > 9 or d < 1)
   {
      cout << (-1);
      return;
   }

   if (a == b or b == c or c == d or a == c or a == d or b == d)
   {
      cout << (-1);
      return;
   }

   if (a + b != row.ff or c + d != row.ss or a + c != col.ff or b + d != col.ss or a + d != dia.ff or b + c != dia.ss)
   {
      cout << (-1);
      return;
   }

   cout << a << sp << b << el << c << sp << d << el;

   return;
}
