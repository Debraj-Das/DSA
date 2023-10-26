// Problem: Palindrome Reorder
// URL: https://cses.fi/problemset/task/1755
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
    string s;
    cin >> s;
    const int n = s.size();
    int freq[26] = {0};
    F(&c, s)
    freq[c - 'A']++;

    int odd = (n & 1), ind = -1;

    f(i, 0, 26)
    {
        if (freq[i] & 1)
        {
            if (odd == 0 or ind != -1)
            {
                cout << "NO SOLUTION" << el;
                return;
            }
            else
                ind = i;
        }

        freq[i] /= 2;
    }

    string ans;
    for (int i = 0, j; i < 26; i++)
    {
        for (j = 0; j < freq[i]; j++)
            ans += ('A' + i);
    }

    cout << ans;
    if (ind != -1)
        cout << (char)('A' + ind);
    reverse(ans.begin(), ans.end());
    cout << ans << el;

    return;
}
