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

const int N = 501;
int dp[N][N], n, ar[N];

int rec(int l, int r)
{
    if (l >= r)
        return 0;

    if (dp[l][r] != (-1))
        return dp[l][r];

    int ans = 0, sum = 0;
    f(i, l, r + 1) sum += ar[i];

    for (int i = l, lf, rt, cs = 0, cans; i < r; i++)
    {
        lf = rec(l, i);
        rt = rec(i + 1, r);

        cs += ar[i];
        cans = cs * (sum - cs) + lf + rt;

        ans = max(ans, cans);
    }

    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    f(i, 0, n) cin >> ar[i];

    memset(dp, -1, sizeof(dp));

    cout << rec(0, n - 1) << el;

    return;
}
