// Problem: D. Equalize the Remainders
// URL: https://codeforces.com/contest/999/problem/D
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

#define int long long
// using ll = long long;
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

   int ar[n], freq[m] = {0};
   rep(i, 0, n)
   {
      cin >> ar[i];
      freq[ar[i] % m]++;
   }

   cout << n << sp << m << el;
   rep(i, 0, n) cout << ar[i] << sp;
   cout << el;

   int idea = n / m, t;

   map<int, int> mpp;
   map<int, V<pii>> change;
   int ans = 0;

   rep(i, 0, 2 * m)
   {
      if (freq[i % m] > idea)
      {
         t = (freq[i % m] - idea);
         mpp[i % m] += t;
         freq[i % m] = idea;
      }
      else if (freq[i % m] < idea)
      {
         t = idea - freq[i % m];
         while (t and !mpp.empty())
         {
            auto it = mpp.begin();
            if (t < it->ss)
            {
               ans += t * (i - it->ff);
               it->ss -= t;
               change[it->ff].pb(mp(i % m, t));
               t = 0;
            }
            else
            {
               ans += it->ss * (i - it->ff);
               t -= it->ss;
               change[it->ff].pb(mp(i % m, it->ss));
               mpp.erase(it->ff);
            }
         }
         freq[i % m] = idea - t;
      }
   }

   cout << ans << el;

   rep(i, 0, n)
   {
      if (change[ar[i] % m].empty())
         continue;
      int j = ar[i] % m;
      auto it = change[j].rbegin();
      int k = (it->ff - j + m) % m;
      ar[i] += k;
      it->ss--;
      if (it->ss == 0)
         change[j].pop_back();
   }

   rep(i, 0, n) cout << ar[i] << sp;
   cout << el;

   return;
}
