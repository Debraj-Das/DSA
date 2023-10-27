// Problem: Stick Lengths
// URL: https://cses.fi/problemset/task/1074
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
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = mod * mod;

#define f(i, a, b) for (int i = a; i < (b); i++)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

using vb = vector<bool>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back

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

void solve()
{
    int n;
    cin >> n;

    int ar[n];
    f(i, 0, n) cin >> ar[i];

    sort(ar, ar + n);

    int pref[n], sum = 0;
    f(i, 0, n)
    {
        sum += ar[i];
        pref[i] = sum;
    }

    int ans = inf;
    f(i, 0, n)
    {
        ans = min(ans, ar[i] * (i + 1) - pref[i] + (sum - pref[i]) - (n - i - 1) * ar[i]);
    }

    cout << ans << el;

    return;
}
