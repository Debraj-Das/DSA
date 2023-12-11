#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rdi(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(rng); }
// shuffle syntex
// shuffle(v.begin(), v.end(), rng); or random_shuffle(perm.begin() + 1, perm.end());
const char alphanum[] = "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "0123456789"
                                  "!@#$%^&*";
inline string rds(const int len)
{
   string st;
   st.reserve(len);
   for (int i = 0; i < len; ++i)
      st += alphanum[rdi(0, (sizeof(alphanum) - 1))];
   return st;
}


using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
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
   int n = rnd(2, 20);
   cout << n << el;

   set<int> used;
   for (int i = 0, x; i < n; i++)
   {
      do
      {
         x = rnd(1, 10);
      } while (used.count(x));

      cout << x << sp;
      used.insert(x);
   }
   cout << el;

   return;
}

int main()
{
   
}
