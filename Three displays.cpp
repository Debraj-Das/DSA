// Problem: H. Three displays
// URL: https://codeforces.com/gym/302977/problem/H
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

int n;
int sz[3001], ct[3001];

int brut()
{
    int cost = INT_MAX;
    for (int i = 0, j, k; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
            for (k = j + 1; k < n; k++)
            {
                if (sz[i] < sz[j] and sz[j] < sz[k])
                {
                    cost = min(cost, ct[i] + ct[j] + ct[k]);
                }
            }

    return eif((cost == INT_MAX), -1, cost);
}

int sol()
{
    int lc[n];
    for (int i = 0, j, c; i < n; i++)
    {
        for (j = i + 1, c = INT_MAX; j < n; j++)
        {
            if (sz[j] > sz[i])
            {
                c = min(c, ct[j]);
            }
        }
        lc[i] = c;

    }

    int cost = INT_MAX;
    for (int i = 0, j; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
        {
            if (sz[i] >= sz[j])
                continue;

            cost = min(cost, ct[i] + ct[j] + lc[j]);
        }

    return eif((cost == INT_MAX), -1, cost);
}

void solve()
{
    cin >> n;
    f(i, 0, n) cin >> sz[i];
    f(i, 0, n) cin >> ct[i];

    cout << sol() << el;

    return;
}
