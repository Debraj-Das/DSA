// Problem: H. Mad City
// URL: https://codeforces.com/contest/1873/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vb vector<bool>
#define vi vector<int>
#define pb push_back

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

int EP;

bool findEntry(const vi gr[], int u, int p, vb &vis)
{
    vis[u] = true;

    F(&v, gr[u])
    {
        if (v != p and vis[v])
        {
            EP = v;
            return true;
        }

        if (v != p and vis[v] == false)
        {
            if (findEntry(gr, v, u, vis))
                return true;
        }
    }

    return false;
}

int dfs(const vi gr[], int u, vb &vis)
{
    vis[u] = true;

    int dist = INT_MAX;
    F(&v, gr[u])
    {
        if (v == EP)
            return 1;

        if (vis[v] == false)
        {
            dist = min(dist, dfs(gr, v, vis) + 1);
        }
    }

    return dist;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vi gr[n + 1];
    vb vis(n + 1, false);

    for (int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }

    findEntry(gr, b, -1, vis);

    int disM, disV;

    vis.assign(n + 1, false);
    disM = eif((a == EP), 0, dfs(gr, a, vis));

    vis.assign(n + 1, false);
    disV = eif((b == EP), 0, dfs(gr, b, vis));

    cout << eif((disV < disM), "YES", "NO") << el;

    return;
}
