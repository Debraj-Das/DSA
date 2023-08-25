// Problem: D. Divisibility by 2^n
// URL: https://codeforces.com/contest/1744/problem/D
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

#define maxa(a, b) a += ((b)-a) * ((b) > a)
#define mina(a, b) a -= (a - (b)) * ((b) < a)

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second

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

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

inline int two(int a)
{
    int ans = 0;
    while (a and !(a & 1))
        ans++, a /= 2;

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    int m = 0;
    f(i, 0, n) m += two(a[i]);

    m = n - m;

    if (m <= 0)
    {
        cout << 0 << el;
        return;
    }

    f(i, 0, n) a[i] = two(i + 1);

    sort(a, a + n, greater<int>());

    int ans;
    for (ans = 0; ans < n and m > 0; ans++)
        m -= a[ans];

    cout << ((m > 0) ? (-1) : ans) << el;

    return;
}
