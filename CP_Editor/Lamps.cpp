// Problem: B. Lamps
// URL: https://codeforces.com/contest/1839/problem/B
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

bool com(pii a, pii b)
{
    if (a.ff < b.ff)
        return true;
    else if ((a.ff == b.ff) and (a.ss > b.ss))
        return true;
    else
        return false;
}

int count(int arr[], int x, int n)
{
    int *low = lower_bound(arr, arr + n, x);
    if (low == (arr + n) || *low != x)
        return 0;

    int *high = upper_bound(low, arr + n, x);

    return high - low;
}

inline void solve()
{
    int n;
    cin >> n;
    pii ab[n];
    int arr[n];
    f(i, 0, n) cin >> ab[i].ff >> ab[i].ss;
    sort(ab, ab + n, com);
    f(i, 0, n) arr[i] = ab[i].ff;

    int ans = 0;
    for (int i = 0, m = 0, x = 0, j = 0; i < n; i++)
        if (ab[i].ff > m)
        {
            ans += ab[i].ss;
            x++;
            if (x > m)
            {
                m = x;
                j = count(arr, m, i + 1);
                x -= j;
            }
        }
    cout << ans << el;

    return;
}
