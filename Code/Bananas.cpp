// Problem: J5 - Bananas
// URL: https://dmoj.ca/problem/ccc05j5
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

inline void solve(string &s);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;

    while (true)
    {
        cin >> s;
        if (s == "X")
            break;

        solve(s);
    }

    return 0;
}

int find(string s)
{
    int b = 1;
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] == 'B')
            b++;
        else if (s[i] == 'S')
        {
            b--;
            if (!b)
                return i;
        }
    }
    return 0;
}

bool check(string s)
{
    size_t l = s.size();
    if (l == 1 && s[0] == 'A')
        return true;
    else if (l > 2)
    {
        if (s[0] == 'A' && s[1] == 'N')
            return check(s.substr(2, l));
        else if (s[0] == 'B')
        {
            int i = find(s);
            if (i > 1)
            {
                if (check(s.substr(1, i - 1)))
                {
                    if (s[i + 1] == 'N')
                        return check(s.substr(i + 2, l));
                    else if (s.substr(i + 1, l).size() == 0)
                        return true;
                }
            }
        }
    }
    return false;
}

inline void solve(string &s)
{
    if (s.size() && check(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}
