// Problem: D. Distinct Split
// URL: https://codeforces.com/contest/1791/problem/D
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
    string s;
    cin >> s;

    short int di[n - 1] = {0}, dsc = 0;
    int ch[26] = {0};
    f(i, 0, n - 1)
    {
        ch[s[i] - 'a']++;
        if (ch[s[i] - 'a'] == 1)
            dsc++;
        di[i] = dsc;
    }

    f(i, 0, 26) ch[i] = 0;
    dsc = 0;
    for (int i = n - 1; i > 0; i--)
    {
        ch[s[i] - 'a']++;
        if (ch[s[i] - 'a'] == 1)
            dsc++;
        di[i - 1] += dsc;
    }

    int ans = 0;
    f(i, 0, n - 1) ans = max(ans, di[i]);
    cout << ans << el;
    return;
}
