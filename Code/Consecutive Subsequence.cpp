// Problem: F. Consecutive Subsequence
// URL: https://codeforces.com/contest/977/problem/F
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

void solve()
{
    int n;
    cin >> n;

    int ar[n];
    f(i, 0, n) cin >> ar[i];

    map<int, int> mp;

    f(i, 0, n)
    {
        if (mp.find(ar[i] - 1) == mp.end())
        {
            mp[ar[i]] = 1;
        }
        else
        {
            mp[ar[i]] = 1 + mp[ar[i] - 1];
        }
    }

    int x, k = 0;

    F(&p, mp)
    {
        if (p.ss > k)
        {
            x = p.ff;
            k = p.ss;
        }
    }

    x -= (k - 1);

    cout << k << el;

    f(i, 0, n)
    {
        if (ar[i] == x)
        {
            cout << (i + 1) << sp;
            x++;
        }
    }

    cout << el;

    return;
}
