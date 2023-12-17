// Problem: C. Equal Sums
// URL: https://codeforces.com/contest/988/problem/C
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

   // int __t ; cin >> __t; while (__t--)
   solve();

   return 0;
}

void solve()
{
   int k, n, x, sum;
   cin >> k;

   vector<int> seq[k];

   rep(i, 0, k)
   {
      cin >> n;
      seq[i].resize(n);
      sum = 0;
      rep(j, 0, n)
      {
         cin >> x;
         seq[i][j] = x;
         sum += x;
      }

      rep(j, 0, n) seq[i][j] = (sum - seq[i][j]);
   }

   map<int, pair<int, int>> m;

   n = seq[0].sz;
   rep(i, 0, n) m[seq[0][i]] = mp(1, i + 1);

   rep(i, 1, k)
   {
      n = seq[i].sz;
      rep(j, 0, n) if (m.find(seq[i][j]) != m.end())
      {
         cout << "YES" << el;
         cout << m[seq[i][j]].ff << sp << m[seq[i][j]].ss << el;
         cout << (i + 1) << sp << (j + 1) << el;
         return;
      }

      rep(j, 0, n) m[seq[i][j]] = mp(i + 1, j + 1);
   }

   cout << "NO" << el;

   return;
}
