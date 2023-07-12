// Problem: D. X-Sum
// URL: https://codeforces.com/contest/1676/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '
#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define F first
#define S second
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

void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void anticlock(int r, int c, vector<vi> &ele, vector<vi> &d, int n, int m)
{
    int i = r, j = c;
    int sum = 0;
    while (i < n and j < m and i >= 0 and j >= 0)
    {
        sum += ele[i][j];
        i++;
        j++;
    }
    i = r;
    j = c;
    while (i < n and j < m and i >= 0 and j >= 0)
    {
        d[i][j] += sum;
        i++;
        j++;
    }
    return;
}

void clock(int r, int c, vector<vi> &ele, vector<vi> &d, int n, int m)
{
    int i = r, j = c;
    int sum = 0;
    while (i < n and j < m and i >= 0 and j >= 0)
    {
        sum += ele[i][j];
        i++;
        j--;
    }
    i = r;
    j = c;
    while (i < n and j < m and i >= 0 and j >= 0)
    {
        d[i][j] += sum;
        i++;
        j--;
    }
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> ele(n, vi(m, 0));
    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> ele[i][j];

    vector<vi> d(n, vi(m, 0));

    for (int i = 0; i < n; i++)
        anticlock(i, 0, ele, d, n, m);
    for (int j = 1; j < m; j++)
        anticlock(0, j, ele, d, n, m);

    for (int j = 0; j < m; j++)
        clock(0, j, ele, d, n, m);
    for (int i = 1; i < n; i++)
        clock(i, m - 1, ele, d, n, m);

    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            d[i][j] -= ele[i][j];

    int ans = 0;
    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            ans = max(ans, d[i][j]);

    cout << ans << el;

    return;
}
