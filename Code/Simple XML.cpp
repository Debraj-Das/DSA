// Problem: B. Simple XML
// Contest: Codeforces - Codeforces Testing Round 2
// URL: https://codeforces.com/problemset/problem/125/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    string s;
    cin >> s;
    string sp = "";
    for (int i = 0; s[i]; i++)
    {
        if (s[i + 1] == '/')
        {
            sp.pop_back();
            sp.pop_back();
            cout << sp << s.substr(i, 4) << el;
            i += 3;
        }
        else
        {
            cout << sp << s.substr(i, 3) << el;
            i += 2;
            sp.push_back(' ');
            sp.push_back(' ');
        }
    }
    return;
}
