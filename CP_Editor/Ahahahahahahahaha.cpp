// Problem: A. Ahahahahahahahaha
// URL: https://codeforces.com/contest/1407/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];
    int no_0 = 0;
    f(i, 0, n) if (a[i] == 0) no_0++;

    if (no_0 >= n / 2)
    {
        cout << no_0 << el;
        f(i, 0, no_0) cout << 0 << sp;
        cout << el;
    }
    else
    {
        no_0 = (n - no_0 - (no_0 & 1));
        cout << no_0 << el;
        f(i, 0, no_0) cout << 1 << sp;
        cout << el;
    }

    return;
}
