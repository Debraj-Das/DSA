// Problem: R. Ksenia and Pan Scales
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/R
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

void solve()
{
   string s, l;
   cin >> s >> l;

   string a, b;
   int n = s.sz, i;
   for (i = 0; i < n and s[i] != '|'; i++)
      a += s[i];

   for (i++; i < n; i++)
      b += s[i];

   int c = abs((int)a.sz - (int)b.sz);
   n = l.sz;
   if (c > n or (n - c) % 2)
   {
      cout << "Impossible";
      return;
   }

   if (a.sz <= b.sz)
   {
      n = b.sz - a.sz;
      for (i = 0; i < n; i++)
         a += l[i];
      c = l.sz - i;
      c /= 2;
      for (n = i + c; i < n; i++)
         a += l[i];
      for (n = i + c; i < n; i++)
         b += l[i];
   }
   else
   {
      n = a.sz - b.sz;
      for (i = 0; i < n; i++)
         b += l[i];
      c = l.sz - i;
      c /= 2;
      for (n = i + c; i < n; i++)
         b += l[i];
      for (n = i + c; i < n; i++)
         a += l[i];
   }

   cout << a << '|' << b;

   return;
}
