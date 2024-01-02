// Problem: E. Reachability from the Capital
// URL: https://codeforces.com/contest/999/problem/E
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

struct DSU
{
   int n, num_grp;
   int *par, *sz;

   DSU()
   {
      n = 0;
      num_grp = 0;
      par = NULL;
      sz = NULL;
   }

   DSU(int n)
   {
      this->n = n;
      num_grp = n;
      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   void reset(int n = 0)
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;

      this->n = n;
      num_grp = n;

      if (n == 0)
      {
         par = NULL;
         sz = NULL;
         return;
      }

      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   ~DSU()
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;
   }

   int find(int u)
   {
      return u == par[u] ? u : par[u] = find(par[u]);
   }

   void merge(int u, int v)
   {
      u = find(u), v = find(v);
      if (u == v)
         return;

      if (sz[u] > sz[v])
         swap(u, v);
      par[u] = v;
      sz[v] += sz[u];
      num_grp--;
   }

   int component()
   {
      return num_grp;
   }

   int sz_component(int u)
   {
      u = find(u);
      return sz[u];
   }
};


/*
// eg.   kruskal Algorithm(MST)
 
   int n, m;
   cin >> n >> m;

   array<int, 3> edgeList[m];
   for (int i = 0, u, v, w; i < m; i++)
   {
      cin >> u >> v >> w;
      edgeList[i][0] = w;
      edgeList[i][1] = u - 1;
      edgeList[i][2] = v - 1;
   }

   sort(edgeList, edgeList + m);

   int price = 0, edge = 0;
   DSU uf(n);
   F(&e, edgeList)
   {
      if (uf.find(e[1]) == uf.find(e[2]))
         continue;

      uf.merge(e[1], e[2]);
      price += e[0];
      edge++;
   }
   
   if(edge == (n-1))
   cout << price << el;
   else
   cout<<"NO Solution"<<el; // MST not possible

*/


void solve()
{
   int 

   return;
}
