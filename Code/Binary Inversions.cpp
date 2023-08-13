// Problem: E. Binary Inversions
// URL: https://codeforces.com/contest/1760/problem/E
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

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define ff first
#define ss second
#define pii pair<int, int>

#define vi vector<int>
#define pb push_back

#define si set<int>

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
    bool a[n];
    f(i, 0, n) cin >> a[i];

    int sum = 0;
    for (int i = n - 1, fal = 0; i >= 0; i--)
        (a[i]) ? sum += fal : fal++;

    int index = 0;
    while (index < n)
    {
        if (a[index] == false)
        {
            a[index] = true;
            break;
        }
        index++;
    }

    int msum = 0;
    for (int i = n - 1, fal = 0; i >= 0; i--)
        (a[i]) ? msum += fal : fal++;

    sum = max(sum, msum);

    if (index < n)
        a[index] = false;

    index = n;
    while (index--)
        if (a[index])
        {
            a[index] = false;
            break;
        }

    msum = 0;
    for (int i = n - 1, fal = 0; i >= 0; i--)
        (a[i]) ? msum += fal : fal++;

    sum = max(sum, msum);

    cout << sum << el;

    return;
}
