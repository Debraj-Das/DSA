// Problem: I. Mike and Fun
// URL: https://codeforces.com/gym/302977/problem/I
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

int m;

int cal(vb &v)
{
    int ans = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (v[i] == false)
            sum = 0;
        else
            sum++;
        ans = max(ans, sum);
    }

    return ans;
}

void solve()
{
    int n, q, i, j;
    cin >> n >> m >> q;

    int x;
    V<vb> bear(n, vb(m, false));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> x;
            bear[i][j] = (x != 0);
        }

    int ans[n];
    for (i = 0; i < n; i++)
    {
        ans[i] = cal(bear[i]);
    }

    while (q--)
    {
        cin >> i >> j;
        i--, j--;
        bear[i][j] = !bear[i][j];

        ans[i] = cal(bear[i]);

        cout << *max_element(ans, ans + n) << el;
    }

    return;
}
