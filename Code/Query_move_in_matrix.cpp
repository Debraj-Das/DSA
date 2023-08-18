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
        if (b & 1)
            x *= a;
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int t ; cin >> t; while (t--)
    solve();

    return 0;
}

void r_rm(int y, set<pii> &row)
{
    auto it = row.lower_bound({y, INT_MIN});
    if (it != row.end() and y >= it->ff and y <= it->ss)
    {
        if (it->ff != y)
            row.insert({it->ff, y - 1});
        if (it->ss != y)
            row.insert({y + 1, it->ss});
        row.erase(it);
    }
    return;
}

void c_rm(int x, set<pii> &col)
{
    auto it = col.lower_bound({x, INT_MIN});
    if (it != col.end() and x >= it->ff and x <= it->ss)
    {
        if (it->ff != x)
            col.insert({it->ff, x - 1});
        if (it->ss != x)
            col.insert({x + 1, it->ss});
        col.erase(it);
    }
    return;
}

void freeze(int &x, int &y, char c, V<set<pii>> &row, V<set<pii>> &col)
{
    switch (c)
    {
    case 'L': {
        if (y <= 1)
        {
            y = -1;
            return;
        }
        y--;
    }
    break;
    case 'R': {
        if (y >= col.size())
        {
            y = -1;
            return;
        }
        y++;
    }
    break;
    case 'U': {
        if (x >= row.size())
        {
            x = -1;
            return;
        }
        x++;
    }
    break;
    case 'D': {
        if (x <= 1)
        {
            x = -1;
            break;
        }
        x--;
    }
    }

    r_rm(y, row[x - 1]);
    c_rm(x, col[y - 1]);

    return;
}

// I assumsed the 1 based index

void solve()
{
    int r, c, q;
    cin >> r >> c >> q;
    int x, y;
    cin >> x >> y;
    string query;
    cin >> query;

    V<set<pii>> row(r);
    f(i, 0, r) row[i].insert({1, c});
    V<set<pii>> col;
    f(i, 0, c) col[i].insert({1, r});

    V<pii> ans;
    ans.pb({x, y});
    r_rm(y, row[x - 1]);
    c_rm(x, col[y - 1]);

    F(&i, query)
    {
        freeze(x, y, i, row, col);
        if (x * y < 0)
            break;
        ans.pb({x, y});
    }

    F(&i, ans)
    cout << i.ff << sp << i.ss << el;
    cout << el;

    return;
}
