// Problem: B. Deadly Laser
// URL: https://codeforces.com/problemset/problem/1721/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

// #define int long long
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

   int __t;
   cin >> __t;
   while (__t--)
      solve();

   return 0;
}

void solve()
{
   int n, m, sx, sy, d;
   cin >> n >> m >> sx >> sy >> d;

   int vis[n][m];
   rep(i, 0, n) rep(j, 0, m) vis[i][j] = false;

   int x, y, ans = -1;
   queue<array<int, 3>> q;
   array<int, 3> t;

   q.push({1, 1, 0});
   vis[0][0] = true;

   while (q.size())
   {
      t = q.front();
      q.pop();

      if (t[0] == n and t[1] == m)
      {
         ans = t[2];
         break;
      }

      // up
      x = t[0] - 1;
      y = t[1];
      if (x > 0 and vis[x - 1][y - 1] == false)
      {
         vis[x - 1][y - 1] = true;
         if (abs(sx - x) + abs(sy - y) > d)
            q.push({x, y, t[2] + 1});
      }

      // down
      x = t[0] + 1;
      y = t[1];
      if (x <= n and vis[x - 1][y - 1] == false)
      {
         vis[x - 1][y - 1] = true;
         if (abs(sx - x) + abs(sy - y) > d)
            q.push({x, y, t[2] + 1});
      }

      // left
      x = t[0];
      y = t[1] - 1;
      if (y > 0 and vis[x - 1][y - 1] == false)
      {
         vis[x - 1][y - 1] = true;
         if (abs(sx - x) + abs(sy - y) > d)
            q.push({x, y, t[2] + 1});
      }

      // right
      x = t[0];
      y = t[1] + 1;
      if (y <= m and vis[x - 1][y - 1] == false)
      {
         vis[x - 1][y - 1] = true;
         if (abs(sx - x) + abs(sy - y) > d)
            q.push({x, y, t[2] + 1});
      }
   }

   cout << ans << el;

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