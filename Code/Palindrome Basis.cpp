// Problem: C. Palindrome Basis
// URL: https://codeforces.com/problemset/problem/1673/C
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

vi pan;

inline bool panlind(string s)
{
   int i = 0, j = s.sz - 1;
   while (i < j)
      if (s[i++] != s[j--])
         return false;
   return true;
}

inline void cal()
{
   for (int i = 1; i < 40001; i++)
      if (panlind(to_string(i)))
         pan.eb(i);
   return;
}

int dp[500][40001];

int rec(size_t i, int sum)
{
   if (sum == 0)
      return 1;
   if (sum < pan[i] or i >= pan.sz)
      return 0;

   if (dp[i][sum] != -1)
      return dp[i][sum];

   dp[i][sum] = (rec(i + 1, sum) + rec(i, sum - pan[i])) % mod;

   return dp[i][sum];
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   cal();
   memset(dp, -1, sizeof(dp));
   int __t, n;
   cin >> __t;
   
   while (__t--)
   {
      cin >> n;
      cout << rec(0, n) << el;
   }

   return 0;
}
