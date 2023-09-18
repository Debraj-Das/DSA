// Problem: C. Bun Lover
// URL: https://codeforces.com/contest/1822/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int __t, n;
    cin >> __t;
    while (__t--)
    {

        cin >> n;
        cout << (n * (n + 2) + 2) << el;
    }

    return 0;
}
