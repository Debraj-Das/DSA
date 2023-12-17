// Problem: D. Points and Powers of Two
// URL: https://codeforces.com/contest/988/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
   int n;
   cin >> n;

   ll ar[n];
   rep(i, 0, n) cin >> ar[i];

   ll ans[2], len = 1;
   ans[0] = ar[0];

   set<ll> st(ar, ar + n);

   rep(i, 0, n)
   {
      for (int j = 0; j < 31; j++)
      {
         ll v = (1ll << j);
         if (st.find(v + ar[i]) != st.end())
         {
            if (st.find(ar[i] + 2 * v) != st.end())
            {
               cout << 3 << el;
               cout << ar[i] << sp << ar[i] + v << sp << ar[i] + 2 * v << el;
               return;
            }

            len = 2;
            ans[0] = ar[i];
            ans[1] = ar[i] + v;
         }
      }
   }

   cout << len << el;
   rep(i, 0, len) cout << ans[i] << sp;

   return;
}
