// Problem: K. Stars Drawing (Easy Edition)
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/K
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
   int n, m;
   cin >> n >> m;

   string sr[n];
   rep(i, 0, n) cin >> sr[i];

   auto check = [&](int i, int j, int l, int r, int u, int d) {
      if (l < 0 or sr[i][l] == '.')
         return false;
      if (r >= m or sr[i][r] == '.')
         return false;
      if (u < 0 or sr[u][j] == '.')
         return false;
      if (d >= n or sr[d][j] == '.')
         return false;

      return true;
   };

   V<array<int, 3>> ans;
   int ar[n][m];
   for (int i = 0, j; i < n; i++)
      for (j = 0; j < m; j++)
         ar[i][j] = 0;

   for (int i = 0, j, s; i < n; i++)
      for (j = 0; j < m; j++)
      {
         if (sr[i][j] == '.')
            continue;

         for (s = 1; check(i, j, j - s, j + s, i - s, i + s); s++)
         {
            ar[i][j - s]++;
            ar[i][j + s]++;
            ar[i - s][j]++;
            ar[i + s][j]++;
         }

         if (s > 1)
         {
            ar[i][j]++;
            ans.pb({i + 1, j + 1, s - 1});
         }
      }

   for (int i = 0, j; i < n; i++)
      for (j = 0; j < m; j++)
         if (sr[i][j] == '*' and ar[i][j] == 0)
         {
            cout << (-1);
            return;
         }

   cout << ans.sz << el;
   for (auto &c : ans)
   {
      cout << c[0] << sp << c[1] << sp << c[2] << el;
   }

   return;
}
