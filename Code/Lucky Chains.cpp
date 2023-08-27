// Problem: D. Lucky Chains
// URL: https://codeforces.com/problemset/problem/1766/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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

const int N = 1e7;

int prime[N] = {0};

void cal()
{
    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2, j; i < N; i++)
        if (prime[i] == 0)
        {
            prime[i] = i;
            for (j = i * i; j < N; j += i)
                prime[j] = i;
        }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cal();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

vi divisor(int n)
{
    vi ans;
    while (prime[n] > 1)
    {
        ans.pb(prime[n]);
        n /= prime[n];
    }
    return ans;
}

void solve()
{
    int x, y;
    cin >> x >> y;

    if (__gcd(x, y) != 1)
    {
        cout << 0 << el;
        return;
    }

    if (x % 2 == y % 2)
    {
        cout << (x % 2) << el;
        return;
    }

    int k = abs(y - x);
    if (k == 1)
    {
        cout << (-1) << el;
        return;
    }

    vi div = divisor(k);

    F(&i, div)
    {
        i -= (x % i);
    }

    int ans = k - (x % k);
    F(&i, div)
    mina(ans, i);

    cout << ans << el;
    return;
}
