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
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline void solve();

const int mod = 1e9 + 7;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a = (a * a) % mod, b >>= 1)
        x = (x * (a * (b & 1) + !(b & 1))) % mod;
    return x;
}

inline void factorial(int fac[], int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (i * fac[i - 1]) % mod;
    return;
}

int fac[200001];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    factorial(fac, 200001);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int num = fac[n + m];
    int dem = (fac[n] * fac[m]) % mod;
    dem = exp(dem, mod - 2);

    int ans = (num * dem) % mod;

    cout << ans << el;

    return;
}
