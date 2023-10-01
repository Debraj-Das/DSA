// Problem: H. The Third Letter
// URL: https://codeforces.com/contest/1850/problem/H
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

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args> void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " : " << arg1 << '\n';
    __f(comma + 1, args...);
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l = 0, int r = 1e9)
{
    return std::uniform_int_distribution<int>(l, r)(rng);
}

#define time(n)                                                                                                        \
    clock_t tt = clock();                                                                                              \
    while ((double)(clock() - tt) / CLOCKS_PER_SEC < n)

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
#define mp make_pair

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
    {
        solve();
    }

    return 0;
}

void dfs(V<pii> gr[], int i, int val, V<pair<int, bool>> &visit)
{
    visit[i].ss = true;
    visit[i].ff = val;

    for (auto &x : gr[i])
    {
        if (visit[x.ff].ss == 0)
            dfs(gr, x.ff, val + x.ss, visit);
    }

    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> gr[n];
    vector<array<int, 3>> c(m);
    int a, b, d;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        gr[b - 1].pb({a - 1, d});
        gr[a - 1].pb({b - 1, -d});
        c[i][0] = a - 1;
        c[i][1] = b - 1;
        c[i][2] = d;
    }

    vector<pair<int, bool>> visit(n, make_pair(0, 0));

    for (int i = 0; i < n; i++)
    {
        if (visit[i].ss == false)
        {
            dfs(gr, i, 1, visit);
        }
    }

    for (int i = 0; i < m; i++)
    {
        a = c[i][0], b = c[i][1], d = c[i][2];
        if ((visit[a].ff - visit[b].ff) != d)
        {
            cout << "NO" << el;
            return;
        }
    }

    cout << "YES" << el;

    return;
}
