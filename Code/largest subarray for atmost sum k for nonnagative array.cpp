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

// example for two pointer : depends => depend on the question
// longest subarray with given sum for non nagative element of array
int two_pointer(int ar[], int n, int sum) // other parameter depends
{
   // intial empty windows left and right side
   int l = 0, r = 0;
   // window value for empty windows depends
   int winVal = 0;
   // the answer for a empty window depends
   int ans = 0;

   while (l < n)
   {
      // moving right side to forward & Second condition depends
      while (r < n and (winVal + ar[r] <= sum))
      {
         // update the window value for include the element ar[r];
         winVal += ar[r];
         r++; // forward the right
      }

      // update the answer for this window. it depends
      ans = max(ans, (r - l));

      // moving left to one step forward
      if (r > l) // non empty window
      {
         // update window value for exclude the element ar[l];
         winVal -= ar[l];
         l++; // forward the left
      }
      else // empty window
      {
         // moving forward completed empty window
         l++;
         r++;
      }
   }

   return ans;
}

void solve()
{
   int n, sum;
   cin >> n >> sum;

   int ar[n];
   rep(i, 0, n) cin >> ar[i];

   cout << two_pointer(ar, n, sum) << el;

   return;
}
