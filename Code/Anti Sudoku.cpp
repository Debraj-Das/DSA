// Problem: D. Anti-Sudoku
// URL: https://codeforces.com/contest/1335/problem/D
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

    int __t;
    cin >> __t;
    while (__t--)
        solve();

    return 0;
}

const int n = 9;
int ar[n][n];

void solve()
{
    int i, j, x;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        for (j = n - 1; j >= 0; j--, x /= 10)
            ar[i][j] = x % 10;
    }

    ar[0][0] = ar[0][1];
    ar[1][4] = ar[1][5];
    ar[2][8] = ar[2][7];
    ar[3][1] = ar[3][2];
    ar[4][5] = ar[4][6];
    ar[5][6] = ar[5][7];
    ar[6][2] = ar[6][3];
    ar[7][3] = ar[7][4];
    ar[8][7] = ar[8][8];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << ar[i][j];
        cout << el;
    }
    return;
}
