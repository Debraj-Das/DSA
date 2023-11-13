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

int n, m;
V<V<pii>> gr;
vi vis;
vi dist;

void dijstra(int sc)
{
    vis.assign(n, 0);
    dist.assign(n, inf);

    dist[sc] = 0;
    pqg<pii> p;
    p.push(mp(0, sc));

    pii fs;
    int neigh, wg;
    while (p.size())
    {
        fs = p.top();
        p.pop();

        if (vis[fs.ss])
            continue;
        vis[fs.ss] = 1;

        for (auto &v : gr[fs.ss])
        {
            neigh = v.ff;
            wg = v.ss;
            if (dist[neigh] > dist[fs.ss] + wg)
            {
                dist[neigh] = dist[fs.ss] + wg;
                p.push(mp(dist[neigh], neigh));
            }
        }
    }

    return;
}

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    int sc;
    cin >> sc;
    dijstra(sc - 1);

    f(i, 0, n) cout << dist[i] << sp;
    cout << el;

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