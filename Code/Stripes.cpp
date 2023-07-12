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
    char m[8][8];
    for (int i = 0, j; i < 8; i++)
        for (j = 0; j < 8; j++)
            cin >> m[i][j];

    // for (int i = 0, j; i < 8; i++)
    // {
    //     for (j = 0; j < 8; j++)
    //         cout << m[i][j];
    //     cout << el;
    // }

    for (int i = 0, j; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if (m[i][j] != 'R')
                break;
        if (j == 8)
        {
            cout << 'R' << el;
            return;
        }
    }
    for (int i = 0, j; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if (m[j][i] != 'B')
                break;
        if (j == 8)
        {
            cout << 'B' << el;
            return;
        }
    }
    cout << "Draw" << el;

    return;
}