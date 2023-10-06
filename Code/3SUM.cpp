// Problem: F. 3SUM
// URL: https://codeforces.com/contest/1692/problem/F
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

bool one(int ar[], int n)
{
    int o = 0;
    f(i, 0, n) if (ar[i] % 10 == 1) o++;

    return (o > 2);
}

vector<int> change(int ar[], int n)
{
    int fr[10] = {0};
    f(i, 0, n) fr[ar[i] % 10]++;

    if (fr[0] > 1 and fr[3])
    {
        return {};
    }

    int tem;
    f(i, 2, 10) if (fr[i] > 1)
    {
        tem = 3 - 2 * i;
        if (tem >= 0 and tem < 10 and fr[tem])
        {
            return {};
        }
        tem = 13 - 2 * i;
        if (tem >= 0 and tem < 10 and fr[tem])
        {
            return {};
        }
        tem = 23 - 2 * i;
        if (tem >= 0 and tem < 10 and fr[tem])
        {
            return {};
        }
    }

    vi ans;
    f(i, 0, 10) if (fr[i]) ans.pb(i);

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int ar[n];
    f(i, 0, n) cin >> ar[i];

    if (one(ar, n))
    {
        cout << "YES" << el;
        return;
    }

    vi av = change(ar, n);

    if (av.size() == 0)
    {
        cout << "YES" << el;
        return;
    }

    n = av.size();
    for (int i = 0, j, k; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                if (((av[i] + av[j] + av[k]) % 10) == 3)
                {
                    cout << "YES" << el;
                    return;
                }
            }
        }
    }

    cout << "NO" << el;

    return;
}
