// Problem: F. L-shapes
// URL: https://codeforces.com/contest/1722/problem/F
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

const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
int n, m;

void solve()
{
    cin >> n >> m;
    char g[n][m];
    int id[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            id[i][j] = 0;
        }
    }
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '*')
            {
                vector<pair<int, int>> adjh, adjv;
                if (i > 0 && g[i - 1][j] == '*')
                {
                    adjh.emplace_back(i - 1, j);
                }
                if (i < n - 1 && g[i + 1][j] == '*')
                {
                    adjh.emplace_back(i + 1, j);
                }
                if (j > 0 && g[i][j - 1] == '*')
                {
                    adjv.emplace_back(i, j - 1);
                }
                if (j < m - 1 && g[i][j + 1] == '*')
                {
                    adjv.emplace_back(i, j + 1);
                }
                if (adjh.size() == 1 && adjv.size() == 1)
                {
                    if (id[i][j] == 0)
                    {
                        id[i][j] = curr;
                    }
                    else
                    {
                        cout << "NO\n";
                        return;
                    }
                    if (id[adjh[0].first][adjh[0].second] == 0)
                    {
                        id[adjh[0].first][adjh[0].second] = curr;
                    }
                    else
                    {
                        cout << "NO\n";
                        return;
                    }
                    if (id[adjv[0].first][adjv[0].second] == 0)
                    {
                        id[adjv[0].first][adjv[0].second] = curr;
                    }
                    else
                    {
                        cout << "NO\n";
                        return;
                    }
                    curr++;
                }
                else if (adjh.size() > 1 || adjv.size() > 1)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '*')
            {
                if (id[i][j] == 0)
                {
                    cout << "NO\n";
                    return;
                }
                else
                {
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (0 <= i + dx[x] && i + dx[x] < n)
                            {
                                if (0 <= j + dy[y] && j + dy[y] < m)
                                {
                                    if (id[i + dx[x]][j + dy[y]] != id[i][j] && id[i + dx[x]][j + dy[y]] != 0)
                                    {
                                        cout << "NO\n";
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "YES\n";

    return;
}
