// Problem: B. Fibonaccharsis
// URL: https://codeforces.com/problemset/problem/1853/B
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

vi v = {0, 1};

void fib()
{
    int x = 1, n;
    while (x < 1e6)
    {
        n = v.size() - 1;
        x = v[n] + v[n - 1];
        v.pb(x);
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fib();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void extendgcd(int a, int b, pii &sol) // pass an arry of size1 3
{
    if (b == 0)
    {
        sol.ff = 1;
        sol.ss = 0;
        return;
    }

    extendgcd(b, a % b, sol);

    int x = sol.ss;
    sol.ss = sol.ff - sol.ss * (a / b);
    sol.ff = x;

    return;
}

void mul(V<vi> &a, const V<vi> &b)
{
    int c[2][2];
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    a[0][0] = c[0][0];
    a[0][1] = c[0][1];
    a[1][0] = c[1][0];
    a[1][1] = c[1][1];

    return;
}

pii coeff(int b)
{
    b -= 2;

    V<vi> ans(2, vi(2, 0));
    ans[0][0] = 1;
    ans[1][1] = 1;

    V<vi> a(2, vi(2, 0));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;

    while (b)
    {
        if (b & 1)
            mul(ans, a);
        mul(a, a);
        b >>= 1;
    }

    return {ans[0][0], ans[0][1]};
}

void solve()
{
    int c, k;
    cin >> c >> k;

    if (k > v.size() or v[k - 1] > c)
    {
        cout << 0 << el;
        return;
    }

    pii tem = coeff(k);

    int a = tem.ss, b = tem.ff;
    int g = __gcd(a, b);

    if (c % g)
    {
        cout << 0 << el;
        return;
    }

    extendgcd(a, b, tem);

    int x = tem.ff * (c / g), y = tem.ss * (c / g);

    int t = (x / (b / g));

    x -= (b / g) * t;
    y += (a / g) * t;

    int ans = (y >= x) ? ((y - x) / (a + b)) + (y >= x) : 0;

    cout << ans << el;

    return;
}
