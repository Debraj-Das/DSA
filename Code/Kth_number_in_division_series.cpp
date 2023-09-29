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

int binary(int lo, int hi, function<bool(int i)> check)
{
    int ans = hi + 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int lcm(int a, int b)
{
    int g;
    if (a == 0 or b == 0)
        g = a ^ b;
    else
        g = __gcd(a, b);

    if (g)
        return (a * b) / g;
    else
        return 0;
}

int lcm_func(int subset[], int n)
{
    int ans = subset[0];
    for (int i = 1; i < n; i++)
        ans = lcm(ans, subset[i]);
    return ans;
}

void cal_lcm(int lcm[], int m, int ar[], int n)
{
    int subset[n], sz;
    for (int i = 1, j, k; i < m; i++)
    {
        for (k = 0, j = i, sz = 0; k < n; k++, j >>= 1)
        {
            if (j & 1)
            {
                subset[sz] = ar[k];
                sz++;
            }
        }
        lcm[i] = lcm_func(subset, sz);
    }
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ar[n];
    f(i, 0, n) cin >> ar[i];

    int lcm[(1 << n)];
    cal_lcm(lcm, (1 << n), ar, n);

    int ans = binary(1, (int)1e19, [&](int mid) {
        int ans = 0;
        for (int i = 1; i < (1 << n); i++)
            ans += (mid / lcm[i]);

        return (ans >= k);
    });

    cout << ans << el;

    return;
}
