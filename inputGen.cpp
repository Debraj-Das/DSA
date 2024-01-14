#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rdi(int l = 0, int r = 1e9)
{
    return std::uniform_int_distribution<int>(l, r)(rng);
}
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

const int N = 51;
bool prime[N];

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

void sieve()
{
    rep(i, 2, N) prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i = 2, j; i * i < N; i++)
    {
        if (prime[i] == false)
            continue;
        for (j = i * i; j < N; j += i)
            prime[j] = false;
    }

    return;
}

int main()
{
	int n = rdi(1, 10);
   cout << n << el;

   rep(i, 0, n) cout << rdi(1, 10000) << sp;

    return 0;
}
