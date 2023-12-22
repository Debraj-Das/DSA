#include <bits/stdc++.h>
using namespace std;

// clang-format off
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rdi(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(rng); }
// clang-format on

inline double rdd(int l = 0, int r = 100000)
{
   double ans = rdi(1000, 1000 * r);
   return ans / 1000;
}

// shuffle(v.begin(), v.end(), rng);  // shuffle syntex

const string a = "abcdefghijklmnopqrstuvwxyz";
const string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num = "0123456789";
const string spec = "!@#$%^&*";

inline char rdc()
{
   const string source = a;
   const int n = source.size() - 1;

   return source[rdi(0, n)];
}

inline string rds(const int len)
{
   const string source = a + A + num + spec;
   const int n = source.size() - 1;
   string st;
   st.reserve(len);

   for (int i = 0; i < len; ++i)
      st += source[rdi(0, n)];
   return st;
}

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const ll INF = 1ll * mod * mod;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);

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

void distinctElements()
{
   int n = rdi(2, 20);
   cout << n << el;

   set<int> used;
   for (int i = 0, x; i < n; i++)
   {
      do
      {
         x = rdi(1, 10);
      } while (used.count(x));

      cout << x << sp;
      used.insert(x);
   }
   cout << el;

   return;
}

void tree()
{
   int n = rdi(2, 20);
   cout << n << el;

   vector<pair<int, int>> edges;
   for (int i = 2; i <= n; ++i)
   {
      edges.emplace_back(rdi(1, i - 1), i);
   }

   // rename the vertice
   vector<int> perm(n + 1);
   for (int i = 1; i <= n; ++i)
   {
      perm[i] = i;
   }
   random_shuffle(perm.begin() + 1, perm.end());

   // random order of edges
   random_shuffle(edges.begin(), edges.end());

   for (pair<int, int> &e : edges)
   {
      if (rdi() % 2)
      {
         // random order of two vertices
         swap(e.first, e.second);
      }

      cout << e.first << sp << e.second << el;
   }
}

inline void graph()
{
   int n = rdi(1, 100), e = rdi(1, 1000), u, v;
   cout << n << sp << e;
   set<pair<int, int>> st;

   while (e--)
   {
      u = rdi(1, n - 1);
      do
      {
         v = rdi(u, n);
      } while (st.find(make_pair(u, v)) != st.end());

      st.insert(make_pair(u, v));

      if (rdi() % 2)
         swap(u, v);

      cout << u << sp << v << el;
   }

   return;
}

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   // int t = rdi(1,20); cout << t<<el; while (t--)
   solve();

   return 0;
}

void solve()
{
   int n = rdi(1,5000);
   cout<<n<<sp<<rdi(1,n)<<el;
   
   rep(i,0,n)
   cout<<rdi(1,5000)<<sp;

   return;
}
