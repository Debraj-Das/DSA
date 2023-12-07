// Problem: U. Knapsack
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
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
int N, W;
int dp[21][101];
int w[21], v[21];

int rec(int n, int wg)
{
   if (n >= N)
      return 0;

   if (dp[n][wg] != -1)
      return dp[n][wg];

   dp[n][wg] = rec(n + 1, wg);

   if (wg + w[n] <= W)
      dp[n][wg] = max(dp[n][wg], rec(n + 1, wg + w[n]) + v[n]);

   return dp[n][wg];
}

void solve()
{
   cin >> N >> W;
   memset(dp, -1, sizeof(dp));

   rep(i, 0, N) cin >> w[i] >> v[i];

   cout << rec(0, 0);

   return;
}
