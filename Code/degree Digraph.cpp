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
void degree(int u, vi gr[], pii deg[]);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

inline void solve()
{
    // Intiallised the Directed Graph(digraph)
    int v;
    cin >> v;
    vi gr[v];
    int e, x, y;
    cin >> e;
    f(i, 0, e)
    {
        cin >> x >> y;
        gr[x].pb(y);
    }

    // calculation indegree (second) and outdegree (first) of digraph
    pii deg[v];

    f(i, 0, v) degree(i, gr, deg);

    // print the indegree and outdegree of the all vertex
    f(i, 0, v) cout << (i) << sp << deg[i].ss << sp << deg[i].ff << el;

    return;
}


void degree(int u, vi gr[], pii deg[])
{
    deg[u].ff = gr[u].size();
    for (int x : gr[u])
        deg[x].ss++;
    return;
}
