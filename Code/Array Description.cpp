// Problem: Array Description
// URL: https://cses.fi/problemset/task/1746
// Memory Limit: 512 MB
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
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vb vector<bool>
#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

V<vi> dp;
vi ar;
int n, m;
const int mod = 1e9 + 7;

int rec(int i, int pre)
{
    while (i < n and ar[i])
    {
        if (i > 0 and pre and abs(ar[i] - pre) > 1)
            return 0;

        pre = ar[i];
        i++;
    }

    if (i == n)
    {
        return 1;
    }

    if (dp[i][pre] != -1)
        return dp[i][pre];

    int ans;
    if (pre)
    {
        if (pre > 1)
            ans = rec(i + 1, pre - 1);
        else
            ans = 0;

        ans = (ans + rec(i + 1, pre)) % mod;

        if (pre < m)
            ans = (ans + rec(i + 1, pre + 1)) % mod;
    }
    else
    {
        ans = rec(i + 1, 1);
        for (int j = 2; j <= m; j++)
            ans = (ans + rec(i + 1, j)) % mod;
    }

    return dp[i][pre] = ans;
}

void solve()
{
    cin >> n >> m;

    dp.resize(n + 1, vi(m + 1, -1));
    ar.resize(n);

    f(i, 0, n) cin >> ar[i];

    cout << rec(0, 0) << el;

    return;
}
