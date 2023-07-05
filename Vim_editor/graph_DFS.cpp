#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define ff first
#define ss second
#define pii pair<int, int>

#define vi vector<int>
#define pb push_back

#define si set<int>

inline int exp(int a, int b)
{
    int x = 1;
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
void dfs(int u, vi gr[], bool visit[]);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    register int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}

inline void solve()
{
    // this is for graph the intialised

    int v;
    cin >> v;
    vi gr[v];
    int e, x, y;
    cin >> e;
    f(i, 0, e)
    {
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }

    // now the main Depth search algorithm implementation
    bool visit[v] = {false};
    f(i, 0, v)
    {
        if (!visit[i])
            dfs(i, gr, visit);
    }

    return;
}

void dfs(int u, vi gr[], bool visit[])
{
    cout << u << sp;
    visit[u] = true;
    for (int v : gr[u])
        if (!visit[v])
            dfs(v, gr, visit);

    return;
}
