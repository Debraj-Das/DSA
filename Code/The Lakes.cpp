// Problem: E. The Lakes
// URL: https://codeforces.com/contest/1829/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    register int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void dfs(const vector<vector<int>> &a, int i, int j, vector<vector<bool>> &visit, int &val);

inline void solve()
{
    int n, m, i, j;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (a[i][j] == 0)
                visit[i][j] = true;

    int ans = 0, val;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (visit[i][j] == false)
            {
                val = 0;
                dfs(a, i, j, visit, val);
                ans = max(ans, val);
            }

    cout << ans << el;

    return;
}

void dfs(const vector<vector<int>> &a, int i, int j, vector<vector<bool>> &visit, int &val)
{
    visit[i][j] = true;
    val += a[i][j];

    if (i > 0 and visit[i - 1][j] == false)
        dfs(a, i - 1, j, visit, val);
    if (i < a.size() - 1 and visit[i + 1][j] == false)
        dfs(a, i + 1, j, visit, val);
    if (j > 0 and visit[i][j - 1] == false)
        dfs(a, i, j - 1, visit, val);
    if (j < a[0].size() - 1 and visit[i][j + 1] == false)
        dfs(a, i, j + 1, visit, val);

    return;
}
