// Problem: D - Iroha and a Grid
// URL: https://atcoder.jp/contests/abc042/tasks/arc058_b
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

#define debug cerr << __LINE__ << "\n"

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

const int N = 200000 + 5;
ll fact[N], invfact[N];

long long invM(ll a)
{
   int b = mod - 2;
   long long ans = 1;

   while (b)
   {
      if (b & 1)
         ans = (1ll * ans * a) % mod;
      a = (1ll * a * a) % mod;
      b >>= 1;
   }

   return ans;
}

void factorialcul()
{
   fact[0] = 1;
   for (int i = 1; i < N; i++)
   {
      fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
   }

   invfact[N - 1] = invM(fact[N - 1]);
   for (int i = N - 2; i >= 0; --i)
   {
      invfact[i] = ((invfact[i + 1] % mod) * (i + 1)) % mod;
   }

   return;
}

ll ncr(ll n, ll r)
{
   if (r > n)
      return 0ll;

   ll res = fact[n] % mod;
   res = (res * (invfact[n - r] % mod)) % mod;
   res = (res * (invfact[r] % mod)) % mod;

   return res;
}

int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t = 1;
   // cin >> t;
   factorialcul();
   for (int cs = 1; cs <= t; cs++)
   {
      // cout << "Case " << cs << ": ";
      solve();
   }

   return 0;
}

void solve()
{
   int h, w, a, b;
   cin >> h >> w >> a >> b;

   ll ans = 0;
   for (int i = h - a, j = b + 1; i > 0 and j <= w; i--, j++)
   {
      ans += (ncr(i - 1 + j - 1, i - 1) * ncr(h - i + w - j, w - j)) % mod;
      ans %= mod;
   }

   cout << ans << el;
}