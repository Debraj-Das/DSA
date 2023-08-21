// Problem: B. Equalize by Divide
// URL: https://codeforces.com/contest/1799/problem/B
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

bool equal(int a[], int n)
{
    f(i, 0, n) if (a[i] != a[0]) return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    if (equal(a, n))
    {
        cout << 0 << el;
        return;
    }

    f(i, 0, n) if (a[i] == 1)
    {
        cout << (-1) << el;
        return;
    }

    pair<int, int> b[n];

    f(i, 0, n)
    {
        b[i].ff = a[i];
        b[i].ss = i + 1;
    }

    sort(b, b + n);
    V<pii> ans;
    while (b[0].ff != b[n - 1].ff)
    {
        for (int i = n - 1; i and b[i].ff != 2; i--)
        {
            while (b[i].ff > b[i - 1].ff)
            {
                ans.pb({b[i].ss, b[i - 1].ss});
                b[i].ff = (b[i].ff / b[i - 1].ff) + ((b[i].ff % b[i - 1].ff) > 0);
            }
        }
        sort(b, b + n);
    }


    cout << ans.size() << el;
    F(&x, ans)
    cout << x.ff << sp << x.ss << el;

    return;
}
