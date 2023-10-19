// Problem: Salary Queries
// URL: https://cses.fi/problemset/task/1144
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

/*
**	Same as Set with some Extra Feature (find_by_order , order_by_key)
     oset<int> s;
     s.insert(23);
     s.insert(34);
     s.insert(6);
    
**  returns an iterator to the element at a given position (0-based index)
     auto x = s.find_by_order(2);
     cout << *x << "\n"; -> 34

**  return the count the smaller element of that element
     s.order_of_key(34); -> return 2
     
** You can use all other set functions like ->
	s.erase(25);
*/

void solve()
{
    int n, q;
    cin >> n >> q;

    int ar[n];

    oset<pii> ost;

    f(i, 0, n)
    {
        cin >> ar[i];
        ost.insert(mp(ar[i], i));
    }

    char c;
    int k, x, a, b;
    while (q--)
    {
        cin >> c;
        if (c == '!')
        {
            cin >> k >> x;
            k--;

            ost.erase(mp(ar[k], k));
            ar[k] = x;
            ost.insert(mp(ar[k], k));
        }
        else
        {
            cin >> a >> b;
            k = ost.order_of_key(mp(a, 0));
            x = ost.order_of_key(mp(b + 1, 0));

            cout << (x - k) << el;
        }
    }

    return;
}
