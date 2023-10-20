// Problem: Distinct Values Queries
// URL: https://cses.fi/problemset/task/1734
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

void solve()
{
    int n, q;
    cin >> n >> q;

    int ar[n];
    f(i, 0, n) cin >> ar[i];

    array<int, 4> qry[q];
    int l, r;
    f(i, 0, q)
    {
        cin >> l >> r;
        l--, r--;
        qry[i][0] = l;
        qry[i][1] = r;
        qry[i][2] = i;
        qry[i][3] = 0;
    }

    sort(qry, qry + q);
    // for (int i = 0; i < q; i++)
    // {
    // cerr << qry[i][0] << sp << qry[i][1] << sp << qry[i][2] << sp << qry[i][3] << el;
    // }
    // cerr << el;

    map<int, int> freq;

    int i = qry[0][0];
    r = qry[0][1];

    while (i <= r)
    {
        freq[ar[i]]++;
        i++;
    }

    qry[0][3] = freq.size();

    for (int k = 1, j; k < q; k++)
    {
        i = qry[k - 1][0];
        l = qry[k][0];
        while (i < l)
        {
            freq[ar[i]]--;
            if (freq[ar[i]] == 0)
                freq.erase(ar[i]);

            i++;
        }
        j = qry[k - 1][1];
        r = qry[k][1];

        if (j < r)
        {
            while (j <= r)
            {
                freq[ar[j]]++;
                j++;
            }
        }
        else
        {
            while (j > r)
            {
                freq[ar[j]]--;
                if (freq[ar[j]] == 0)
                    freq.erase(ar[j]);

                j--;
            }
        }

        qry[k][3] = freq.size();
    }

    sort(qry, qry + q, [](array<int, 4> a, array<int, 4> b) { return a[2] < b[2]; });

    for (i = 0; i < q; i++)
    {
        // cerr << qry[i][0] << sp << qry[i][1] << sp << qry[i][2] << sp << qry[i][3] << el;
        cout << qry[i][3] << el;
    }

    return;
}
