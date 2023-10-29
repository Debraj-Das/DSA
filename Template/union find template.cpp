/*
    "Arise! Awake! And stop not until the goal is reached."
    "You cannot believe in God until you believe in yourself."
    "Talk to yourself once in a day, otherwise you may miss meeting an intelligent person in this world."
    "We are what our thoughts have made us; so take care about what you think.
                    Words are secondary. Thoughts live; they travel far."
                                                        by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = mod * mod;

#define f(i, a, b) for (int i = a; i < (b); i++)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

using vb = vector<bool>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
   int x;
   for (x = 1; b; a *= a, b >>= 1)
      x *= (a * (b & 1) + !(b & 1));
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

void solve()
{
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

   return;
}

/*
  After Solving the any problems
    1. Go through the solution
    2. Go through editiorial
    3. Make note ->
        a. Didied the into keys steps
        b. Topic and level(out of 100)
        etc..
    4. What new points you discover from this problems
        a. insight
        b. intuition
        c. process (steps of both)
    etc...
*/