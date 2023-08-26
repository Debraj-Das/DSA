// Problem: D. Matryoshkas
// URL: https://codeforces.com/contest/1790/problem/D
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
#define mp make_pair

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

int num(V<pii> &v, int a, int b)
{
    if (b == a)
        return 0;
    if (b == a + 1)
        return v[a].ss;

    int Min = INT_MAX;
    for (int i = a; i < b; i++)
        mina(Min, v[i].ss);

    for (int i = a; i < b; i++)
        v[i].ss -= Min;

    int ans = Min;
    for (int i = a, j; i < b; i = j + 1)
    {
        for (j = i; (j < b) and v[j].ss; j++)
            ;
        ans += num(v, i, j);
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    sort(a, a + n);

    V<pii> v;
    for (int i = 0, j; i < n; i = j)
    {
        for (j = i + 1; j < n and a[j - 1] == a[j]; j++)
            ;
        v.pb(mp(a[i], j - i));
    }

    int ans = 0;
    n = v.size();
    for (int i = 0, j; i < n; i = j)
    {
        for (j = i + 1; j < n and v[j - 1].ff + 1 == v[j].ff; j++)
            ;
        ans += num(v, i, j);
    }

    cout << ans << el;

    return;
}
