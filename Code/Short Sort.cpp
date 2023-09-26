// Problem: A. Short Sort
// URL: https://codeforces.com/problemset/problem/1873/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

#define el '\n'

#define eif(cds, a, b) ((cds) ? (a) : (b))

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int __t, v;
    char a, b, c;
    cin >> __t;
    while (__t--)
    {
        cin >> a >> b >> c;

        v = (a == 'a') + (b == 'b') + (c == 'c');

        cout << eif(v, "YES", "NO") << el;
    }

    return 0;
}
