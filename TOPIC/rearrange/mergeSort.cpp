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

void merge(int ar[], int l, int r)
{
   if (l >= r)
      return;
   int mid = (l + r) / 2;
   merge(ar, l, mid);
   merge(ar, mid + 1, r);

   const int n = (r - l + 1);
   int temp[n], i, j, k;
   for (i = l, j = mid + 1, k = 0; i <= mid and j <= r; k++)
   {
      if (ar[i] <= ar[j])
      {
         temp[k] = ar[i];
         i++;
      }
      else
      {
         temp[k] = ar[j];
         j++;
      }
   }

   while (i <= mid)
   {
      temp[k] = ar[i];
      i++, k++;
   }

   while (j <= r)
   {
      temp[k] = ar[j];
      j++, k++;
   }

   for (i = l, k = 0; i <= r; i++, k++)
      ar[i] = temp[k];

   return;
}

void solve()
{
   int n;
   cin >> n;

   int ar[n];
   rep(i, 0, n)
   {
      cin >> ar[i];
   }

   merge(ar, 0, n - 1);

   rep(i, 0, n) cout << ar[i] << sp;

   return;
}
