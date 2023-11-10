// Problem: Binomial Coefficients
// URL: https://cses.fi/problemset/task/1079
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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

inline int exp(int a)
{
   int b = mod - 2, ans = 1;
   while (b)
   {
      if (b & 1)
         ans = (ans * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
   }
   // cerr << ans << el;
   return ans;
}

inline void solve();

const int N = 1e6 + 1;
int C[N], inv[N];
void cal()
{
   C[0] = 1;
   inv[0] = 1;
   for (int i = 1; i < N; i++)
   {
      C[i] = (C[i - 1] * i) % mod;

      inv[i] = exp(C[i]);
   }

   return;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   cal();
   int __t, a, b;
   cin >> __t;
   while (__t--)
   {
      cin >> a >> b;
      cout << (((C[a] * inv[a - b]) % mod) * inv[b]) % mod << el;
   }

   return 0;
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