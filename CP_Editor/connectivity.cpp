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

#define ff first
#define ss second
#define si set<int>
#define vi vector<int>
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

void bfs(int i, vi gr[], int id[], const int n_i)
{
    queue<int> q;
    q.push(i);
    int ele;
    while (!q.empty())
    {
        ele = q.front();
        q.pop();
        id[ele] = n_i;
        for (auto x : gr[ele])
            if (!id[x])
                q.push(x);
    }
    return;
}

inline void solve()
{
    int V;
    cin >> V;
    vi gr[V];
    int e, x, y;
    cin >> e;
    f(i, 0, e)
    {
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    int id[V] = {0};
    int n_i = 0;
    f(i, 0, V) if (!id[i]) n_i++, bfs(i, gr, id, n_i);

    int q;
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        if (id[x] == id[y])
            cout << "YES" << el;
        else
            cout << "NO" << el;
    }

    return;
}
