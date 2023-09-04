// Problem: B. Getting Zero
// URL: https://codeforces.com/contest/1661/problem/B
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
#define mina(a, b) a -= (a - (b)) * ((b) < a)
#define min(a, b) ((a) < (b)) ? (a) : (b)
inline void solve();

const int N = 32769;

int cot[N] = {15};

void cal()
{
    for (int i = 1, j, k; i < N; i++)
    {
        if (cot[i])
            continue;
        for (j = 2 * i, k = 1; j < N; j *= 2, k++)
            cot[j] = k;
    }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cal();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    int ans = min(15, 32768 - n);
    f(i, 0, ans) mina(ans, (15 - cot[n + i] + i));

    cout << ans << sp;

    return;
}