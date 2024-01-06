// Problem: G. Smallest Product
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/G
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

inline ld exp(ld a, int b)
{
   ld x = 1;
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

ll binary(ll lo, ll hi, function<bool(ll)> check)
{
   ll ans = hi + 1, mid;
   while (lo <= hi)
   {
      mid = (lo + hi) / 2;
      if (check(mid))
      {
         ans = mid;
         hi = mid - 1;
      }
      else
      {
         lo = mid + 1;
      }
   }

   return ans;
}
/* How to used the binary function in binary search operation
1. lower ranage = lo , higher range = hi ;
2. check function => which respect the solution space is NNNNNYYYYY(first no then yes)

auto check = [&](int mid) {
    // body of the check function
    // return true or false depend on mid ;
}

    int ar[n] ;
eg. int ans = binary(0, n - 1, [&](int i) { return ar[i] < ar[0]; });

*/

void solve()
{
   int n;
   cin >> n;

   ld res = 1, x;
   rep(i, 0, n)
   {
      cin >> x;
      res *= x;
   }

   ll ans = binary(1L, 1e10L, [&](ll mid) {
      ld t = exp(mid, n);
      return t > res;
   });

   cout << ans;

   return;
}

