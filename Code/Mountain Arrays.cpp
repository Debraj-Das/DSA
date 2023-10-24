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

void test();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t;
    // cin >> __t;
    // while (__t--)
    // solve();

    int t = 0;
    time(5)
    {
        t++;
        test();
    }

    cerr << t << el;

    return 0;
}

#ifndef ONLINE_JUDGE
#define darr(a, n)                                                                                                     \
    std::cerr << #a << " : [ ";                                                                                        \
    for (int i = 0; i < n; i++)                                                                                        \
        std::cerr << a[i] << ' ';                                                                                      \
    std::cerr << "]\n";
#define dmat(mat, row, col)                                                                                            \
    std::cerr << #mat << " :\n";                                                                                       \
    for (int i = 0; i < row; i++)                                                                                      \
    {                                                                                                                  \
        for (int j = 0; j < col; j++)                                                                                  \
            std::cerr << mat[i][j] << ' ';                                                                             \
        std::cerr << '\n';                                                                                             \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t)
{
    cerr << str << ":" << t << "\n";
}
template <class T, class... S> void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << ":" << t << ",";
    dbs(str.substr(idx + 1), s...);
}
#define dstl(x)                                                                                                        \
    std::cerr << #x << " : ";                                                                                          \
    _p(x);                                                                                                             \
    std::cerr << endl;
void _p(auto t)
{
    std::cerr << t;
}
template <class T, class V> void _p(std::pair<T, V> p)
{
    std::cerr << "{ ";
    _p(p.first);
    std::cerr << ", ";
    _p(p.second);
    std::cerr << " }";
}
template <class T> void _p(std::vector<T> v)
{
    std::cerr << "[ ";
    for (const auto &i : v)
    {
        _p(i);
        std::cerr << " ";
    }
    std::cerr << "]";
}
template <class T> void _p(std::set<T> v)
{
    std::cerr << "[ ";
    for (const auto &i : v)
    {
        _p(i);
        std::cerr << " ";
    }
    std::cerr << "]";
}
template <class T> void _p(std::multiset<T> v)
{
    std::cerr << "[ ";
    for (const auto &i : v)
    {
        _p(i);
        std::cerr << " ";
    }
    std::cerr << "]";
}
template <class T, class V> void _p(std::map<T, V> v)
{
    std::cerr << "[ ";
    for (const auto &i : v)
    {
        _p(i);
        std::cerr << " ";
    }
    std::cerr << "]";
}
template <class T, class V> void _p(std::unordered_map<T, V> v)
{
    std::cerr << "[ ";
    for (const auto &i : v)
    {
        _p(i);
        std::cerr << " ";
    }
    std::cerr << "]";
}
#else
#define pr(...)                                                                                                        \
    {                                                                                                                  \
    }
#define darr(a, n)                                                                                                     \
    {                                                                                                                  \
    }
#define dmat(mat, row, col)                                                                                            \
    {                                                                                                                  \
    }
#define dstl(x)                                                                                                        \
    {                                                                                                                  \
    }
#endif

struct randomNumber
{
    int l, r;
    randomNumber(int l = INT_MIN, int r = INT_MAX)
    {
        this->l = l;
        this->r = r;
    }

    int rdi()
    {
        return std::uniform_int_distribution<int>(l, r)(rng);
    }

    // Random vector
    std::vector<int> rdv(int n)
    {
        std::vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = rdi();
        return v;
    }

    // Random array
    void rda(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
            arr[i] = rdi();
        return;
    }
};

/*
    Add this line before used it if it is not present
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    randomNumber rn(0, 1000);
    rn.rdi() -> give any random number from 0 to 1000
    rn.rdv(10) -> give 10 length vector with 0 to 1000 element
    rn.rda(ar, n) -> filled with 0 to 1000 random numbers
*/

int dp[1001][1001][2];
int m, k;
int ar[1001];

int rec(int n, int i, bool r)
{
    if (n == m)
    {
        int l, ri;
        if (r == 0)
            l = i, ri = n - 1;
        else
            l = n - 1, ri = i;

        bool ans = ((l and abs(ar[l] - ar[m]) <= k) and (ri and abs(ar[m] - ar[ri]) <= k));

        return ans;
    }

    if (dp[n][i][r] != -1)
        return dp[n][i][r];

    int ans = 0;
    if (n == 1 or abs(ar[n - 1] - ar[n]) <= k)
        ans += rec(n + 1, i, r);

    if (i == 0 or abs(ar[i] - ar[n]) <= k)
        ans += rec(n + 1, n - 1, 1 - r);

    return dp[n][i][r] = ans;
}

int brut(int n, int l, int r)
{
    if (n == m)
    {
        bool ans = ((l and abs(ar[l] - ar[m]) <= k) and (r and abs(ar[m] - ar[r]) <= k));

        return ans;
    }

    int left = 0;
    int right = 0;

    if (l == 0 or abs(ar[l] - ar[n]) <= k)
        left = brut(n + 1, n, r);

    if (r == 0 or abs(ar[r] - ar[n]) <= k)
        right = brut(n + 1, l, n);

    int ans = left + right;

    return ans;
}

void test()
{
    m = rnd(2, 20);
    randomNumber rn(1, 10000);
    rn.rda(ar, m + 1);

    sort(ar + 1, ar + 1 + m);
    memset(dp, -1, sizeof(dp));

    if (brut(1, 0, 0) != rec(1, 0, 1))
    {
        darr(ar, m + 1);
    }

    return;
}

void solve()
{
    cin >> m >> k;
    pr(m, k);

    f(i, 1, m + 1) cin >> ar[i];

    sort(ar + 1, ar + m + 1);

    darr(ar, m);

    memset(dp, -1, sizeof(dp));

    // cout << brut(1, 0, 0) << el;
    cout << rec(1, 0, 1) << el;

    return;
}
