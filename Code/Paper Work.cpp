// Problem: A. Paper Work
// URL: https://codeforces.com/problemset/problem/250/A
//
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
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    f(i, 0, n) cin >> arr[i];
    vi re;
    int days = 0;
    for (int i = 0, no = 0; i < n; i++, days++)
    {
        if (arr[i] < 0)
            no++;
        if (no == 3)
        {
            no = 1;
            re.push_back(days);
            days = 0;
        }
    }
    if (days)
        re.push_back(days);
    cout << (re.size()) << el;
    for (int x : re)
        cout << x << sp;
    cout << el;
    return;
}
