// Problem: M. Postcard
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/M
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
   int k;
   string s;
   cin >> s >> k;

   int alp = 0, star = 0, candy = 0;
   for (char &c : s)
      if (c == '*')
         star++;
      else if (c == '?')
         candy++;
      else
         alp++;

   // cerr << s << sp << alp << sp << candy << sp << star << el;

   string ans;

   if (alp < k)
   {
      if (star == 0)
      {
         cout << "Impossible";
         return;
      }

      candy = k - alp;
      for (char &c : s)
         if (c >= 'a' and c <= 'z')
            ans += c;
         else if (c == '*')
         {
            char r = ans.back();
            while (candy > 0)
            {
               ans += r;
               candy--;
            }
         }
   }
   else
   {
      if ((candy + star) < (alp - k))
      {
         cout << "Impossible";
         return;
      }
      // cerr << s << sp << alp << sp << k << el;

      candy = alp - k;
      for (char &c : s)
         if (c == '*' or c == '?')
         {
            if (candy > 0)
               ans.pop_back(), candy--;
         }
         else
            ans += c;
   }

   cout << ans;

   return;
}
