// Problem: B. Conveyor Belts
// Contest: Codeforces - Codeforces Round 863 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1811/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

int cor(int x, int y, int m)
{
    if (x > m)
        x = (2 * m - x + 1);
    if (y > m)
        y = (2 * m - y + 1);
    return min(x, y);
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ans = cor(x, y, n / 2);
    cin >> x >> y;
    ans = abs(ans - cor(x, y, n / 2));
    cout << ans << el;
    return;
}
