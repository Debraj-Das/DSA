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
const int mod = 1e9 + 7;
const int inf = mod * mod;

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

// Zero one Graph
int n, m;
V<V<pii>> gr;
vi vis;

void distance(int u)
{
    vis.assign(n, inf);
    vis[u] = 0;

    deque<int> q;
    q.push_back(u);
    while (q.size())
    {
        u = q.front();
        q.pop_front();

        for (auto &v : gr[u])
        {
            if (vis[v.ff] > vis[u] + v.ss)
            {
                vis[v.ff] = vis[u] + v.ss;

                if (v.ss)
                    q.push_back(v.ff);
                else
                    q.push_front(v.ff);
            }
        }
    }

    return;
}

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    int u, v, w;

    f(i, 0, m)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    distance(0);

    f(i, 0, n)
    {
        cout << eif((vis[i] == inf), -1, vis[i]) << sp;
    }
    cout << el;

    return;
}
