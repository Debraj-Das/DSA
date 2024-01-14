// Problem: C. Summarize to the Power of Two
// URL: https://codeforces.com/contest/1005/problem/C
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
   int n;
   cin >> n;

   int ar[n];
   rep(i, 0, n) cin >> ar[i];
   sort(ar, ar + n);

   bool ans[n] = {false};

   for (int i = 0, j; i < n; i++)
   {
      for (j = 1; j < 32; j++)
      {
         ll f = (1ll << j) - ar[i];
         if (f < ar[0])
            continue;
         if (f > ar[n - 1])
            break;

         if (i > 0 and binary_search(ar, ar + i, f))
         {
            ans[i] = true;
            break;
         }
         if (i < n - 1 and binary_search(ar + i + 1, ar + n, f))
         {
            ans[i] = true;
            break;
         }
      }
   }

   int res = 0;
   rep(i, 0, n) if (ans[i] == false) res++;

   cout << res;

   return;
}
