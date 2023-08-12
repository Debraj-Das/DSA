// Problem: F. Eating Candies
// URL: https://codeforces.com/contest/1669/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define el '\n'

#define f(i, a, b) for (int i = a; i < (b); i++)

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    register int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

inline void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    int l = -1, r = n;
    for (int i = 0, j = n - 1, alice = 0, bob = 0; i <= j; i++)
    {

        for (alice += a[i]; (alice > bob) and (i < j); j--)
            bob += a[j];

        if (alice == bob)
            l = i, r = j + 1;
    }

    cout << (l + 1) + (n - r) << el;

    return;
}
