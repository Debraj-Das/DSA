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
        solve();

    return 0;
}

int n, m, k;

int bfs(const V<vi> &gr, int u, bool vis[], vi &ele, int arr[])
{
    ele.pb(arr[u]);

    int ans = INT_MAX;
    if (gr[u].empty() and ele.size() >= k)
    {
        f(i, 0, k) mina(ans, ele[i]);

        int p = ele.size();
        f(i, k, p) maxa(ans, ele[i]);
    }

    vis[u] = true;

    F(&x, gr[u])
    {
        if (vis[x] == false)
            maxa(ans, bfs(gr, x, vis, ele, arr));
    }

    ele.pop_back();

    return eif((ele.size() < k), -1, ans);
}

void solve()
{
    cin >> n >> m >> k;
    int arr[n];
    f(i, 0, n) cin >> arr[i];

    V<vi> gr(n);
    int u, v;
    f(i, 0, m)
    {
        cin >> u >> v;
        u--, v--;
        gr[u].pb(v);
        gr[v].pb(u);
    }

    int ans = -1;
    bool vis[n] = {0};
    vi ele;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            maxa(ans, bfs(gr, i, vis, ele, arr));
    }

    cout << ans << el;

    return;
}