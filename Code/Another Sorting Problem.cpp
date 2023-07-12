// Problem: A. Another Sorting Problem
// URL: https://codeforces.com/contest/1575/problem/A
// Memory Limit: 512 MB
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
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

bool compare(pair<string, int> &fi, pair<string, int> &se)
{
    string a = fi.F, b = se.F;
    for (int i = 0; a[i]; i++)
    {
        if (a[i] < b[i])
            return (i & 1) ? false : true;
        else if (b[i] < a[i])
            return (i & 1) ? true : false;
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    pair<string, int> v[n];
    f(i, 0, n)
    {
        cin >> v[i].F;
        v[i].S = (i + 1);
    }
    sort(v, v + n, compare);
    f(i, 0, n) cout << v[i].S << sp;
    cout << el;

    return;
}
