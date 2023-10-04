// Problem: E1. Rubik's Cube Coloring (easy version)
// URL: https://codeforces.com/contest/1594/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

const int mod = 1e9 + 7;

inline int expo(int b)
{
    int x = 1, a = 4;
    while (b)
    {
        if (b & 1)
            x = (x * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    cout << (6 * expo((1ll << n) - 2)) % mod << el;

    return 0;
}
