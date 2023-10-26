// Problem: Chessboard and Queens
// URL: https://cses.fi/problemset/task/1624
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

const int n = 8;
string broad[n];
bool p[n][n];
bool col[n];
int ans = 0;

inline bool corner(int r, int c)
{
    // up and left corner
    int i = r - 1, j = c - 1;
    while ((i >= 0 and i < n) and (j >= 0 and j < n))
    {
        if (p[i][j])
            return false;
        i--, j--;
    }

    // up and right corner
    i = r - 1, j = c + 1;
    while ((i >= 0 and i < n) and (j >= 0 and j < n))
    {
        if (p[i][j])
            return false;
        i--, j++;
    }

    // down and left corner
    i = r + 1, j = c - 1;
    while ((i >= 0 and i < n) and (j >= 0 and j < n))
    {
        if (p[i][j])
            return false;
        i++, j--;
    }

    //  down and right corner
    i = r + 1, j = c + 1;
    while ((i >= 0 and i < n) and (j >= 0 and j < n))
    {
        if (p[i][j])
            return false;
        i++, j++;
    }

    return true;
}

void pos(int i)
{
    if (i == n)
    {
        ans++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (broad[i][j] != '*' and col[j] == false and corner(i, j))
        {
            col[j] = true;
            p[i][j] = true;
            pos(i + 1);
            col[j] = false;
            p[i][j] = false;
        }
    }

    return;
}

void solve()
{
    f(i, 0, n)
    {
        cin >> broad[i];
        col[i] = false;
    }

    for (int i = 0, j; i < n; i++)
        for (j = 0; j < n; j++)
            p[i][j] = false;

    ans = 0;

    pos(0);

    cout << ans << el;

    return;
}
