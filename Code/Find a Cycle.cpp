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
#define si set<int>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

bool cycle(int u, vi gr[], bool visit[], int pre)
{
    visit[u] = true;
    for (int v : gr[u])
    {
        if (v != pre and visit[v])
            return true;
        else if (!visit[v])
            return cycle(v, gr, visit, u);
    }
    return false;
}

inline void solve()
{
    // Intialised the Graph
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

    // Algorithm for finding Cycle in Graph
    bool visit[v] = {false}, cy = false;

    f(i, 0, v)
    {
        if (!visit[i] and cycle(i, gr, visit, -1))
        {
            cy = true;
            break;
        }
    }

    // output of the Cycle finding
    cout << eif(cy, "yes", "no") << el;

    return;
}
