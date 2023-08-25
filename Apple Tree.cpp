// Problem: D. Apple Tree
// URL: https://codeforces.com/contest/1843/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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

void dfs(const V<vi> &gr, int i, int p, int n, int a[])
{
    if (p != -1 and gr[i].size() == 1)
    {
        a[i] = 1;
        return;
    }

    a[i] = 0;

    F(&x, gr[i])
    if (x != p)
    {
        dfs(gr, x, i, n, a);
        a[i] += a[x];
    }

    return;
}

void left(int a[], int n)
{
    V<vi> gr(n);
    int x, y;
    f(i, 1, n)
    {
        cin >> x >> y;
        gr[x - 1].pb(y - 1);
        gr[y - 1].pb(x - 1);
    }

    dfs(gr, 0, -1, n, a);

    return;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];

    left(a, n);

    int q;
    cin >> q;
    int x, y;
    while (q--)
    {
        cin >> x >> y;
        cout << a[x - 1] * a[y - 1] << el;
    }

    return;
}
