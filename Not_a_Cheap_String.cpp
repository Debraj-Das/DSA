// Problem: D. Not a Cheap String
// URL: https://codeforces.com/contest/1702/problem/D
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

void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    string s;
    cin >> s;
    int p;
    cin >> p;
    int cost = 0, n = s.length();
    f(i, 0, n) cost += (s[i] - 'a' + 1);
    vector<pair<char, int>> com(s.length());
    f(i, 0, n)
    {
        com[i].F = s[i];
        com[i].S = i;
    }
    sort(com.begin(), com.end());
    f(i, 0, n)
    {
        if (cost > p)
        {
            cost -= (com[i].F - 'a' + 1);
            s.erase(com[i].S, 1);
        }
        else
            break;
    }
    cout << s << el;
    return;
}
