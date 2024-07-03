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
// const int mod = 1e9 + 7;
// const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))
#define setpr(x) cout << setprecision(x) << fixed

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int TC = 1;
   // cin >> TC;
   for (int i = 0; i < TC; i++)
   {
      // cout<<"case "<<(i+1)<<": ";
      solve();
      cout << '\n';
   }

   return 0;
}

int gcd(int a, int b)
{
   if (a == 0 or b == 0)
      return (a ^ b);
   return __gcd(a, b);
}

void extendgcdUtills(int a, int b, pair<int, int> &ans)
{
   if (b == 0)
   {
      ans.first = 1;
      ans.second = 0;
      return;
   }

   extendgcdUtills(b, a % b, ans);
   int x = ans.second;

   ans.second = ans.first - ans.second * (a / b);
   ans.first = x;

   return;
}

pair<int, int> Egcd(int a, int b, int c)
{
   int g = gcd(a, b);
   
   // answer not present if c%g != 0
   if (c % g != 0)
      return make_pair(0, 0);

   pair<int, int> ans;
   extendgcdUtills(a, b, ans);

   int k = c / g;
   ans.first *= k;
   ans.second *= k;

   /*
      There are infinity solution
      ans.first = ans.first + (b/g)*t;
      ans.second = ans.second - (a/g)*t;
      here t is any interger
   */

   return ans;
}

void solve()
{
   pair<int, int> ans = Egcd(2, 2, 8);
   cout << ans.first << sp << ans.second << el;

   return;
}
