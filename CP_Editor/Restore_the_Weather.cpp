// Problem: B. Restore the Weather
// Contest: Codeforces - Codeforces Round 874 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1833/B
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
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
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
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    f(i, 0, n) cin >> a[i];
    f(i, 0, n) cin >> b[i];
    pair<int, int> p[n];
    f(i, 0, n)
    {
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p, p + n);
    sort(b, b +n);
    f(i, 0, n) a[p[i].second] = b[i];
    f(i, 0, n) cout << a[i] << ' ';
    cout << el;

    return;
}