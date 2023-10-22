// Problem: E. Cyclic Components
// URL: https://codeforces.com/contest/977/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

void dfs(const vi gr[], int u, int p, vb &vis, bool &cycle)
{
    vis[u] = true;

    cycle &= (gr[u].size() == 2);

    F(&v, gr[u])
    {
        if (vis[v])
            continue;

        dfs(gr, v, u, vis, cycle);
    }

    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vi gr[n];

    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        gr[u].pb(v);
        gr[v].pb(u);
    }

    int ans = 0;
    vb vis(n, false);
    bool cycle;

    f(i, 0, n)
    {
        if (vis[i])
            continue;

        cycle = (gr[i].size() == 2);

        dfs(gr, i, -1, vis, cycle);

        ans += cycle;
    }

    cout << ans << el;

    return;
}