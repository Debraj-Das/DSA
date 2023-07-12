// Problem: B. Grid Reconstruction
// Contest: Codeforces - Codeforces Round 865 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1816/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)
#define vi vector<int>
#define max(a, b) (a) > (b) ? (a) : (b)

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
    cout << (2 * n) << ' ';
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
            cout << (i + 1) << ' ';
        else
            cout << (2 * n - i) << ' ';
    }
    cout << el;
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
            cout << (i) << ' ';
        else
            cout << (2 * n - i - 1) << ' ';
    }
    cout << (2 * n - 1) << el;

    return;
}
