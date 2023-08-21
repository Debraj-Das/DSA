// Problem: B. Playing in a Casino
// URL: https://codeforces.com/contest/1808/problem/B
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

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n, m;
    cin >> m >> n;

    int a[n][m];
    for (int j = 0, i; j < m; j++)
        for (i = 0; i < n; i++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + m);

    int sum, ans = 0;

    for (int i = 0, j; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < m; j++)
            sum += a[i][j];

        for (j = 0; j < m; j++)
        {
            ans += (sum - (m - j) * a[i][j]);
            sum -= a[i][j];
        }
    }

    cout << ans << el;

    return;
}