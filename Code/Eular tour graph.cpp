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
vi Eular(vector<vector<bool>> &gr);

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
    // iniasized the graph as adjecy list
    int v;
    cin >> v;
    vector<vector<bool>> gr(v, vector<bool>(v, false));
    int e, x, y;
    cin >> e;
    f(i, 0, e)
    {
        cin >> x >> y;
        gr[x][y] = true;
        gr[y][x] = true;
    }

    // find out the algorithm
    vi path = Eular(gr);

    // print the output
    if (path.size())
    {
        for (int i : path)
            cout << i << sp;
        cout << el;
    }
    else
        cout << "no" << el;

    return;
}

// Finding the path using Eular algorithm O(v^3 , v^2)
vi Eular(vector<vector<bool>> &gr)
{
    const int v = gr.size();
    vi path;
    path.pb(0);
    for (int i = 0, j; i < v; i = j)
    {
        for (j = 0; j < v; j++)
            if (gr[i][j])
            {
                path.pb(j);
                gr[i][j] = false;
                gr[j][i] = false;
                break;
            }
    }

    for (int i = 0, j; i < v; i++)
        for (j = 0; j < v; j++)
            if (gr[i][j])
                return {};

    return path;
}
