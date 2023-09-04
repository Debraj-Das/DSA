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

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

/*
    Partial sum ->
    1. create a new array p of size n
    2. for each query +LRX
        -> p[L] += x ;
        -> p[R+1] -= x ;

    3. after all query, Build prefix sum array of p(in place)


    AP of partial sum ->
    **Modified the second
    arr[L] += a ;
    arr[R+1] -= (a + (R-L)*d);
    drr[L+1] += d ;
    drr[R+1] -= d ;

    ** Different approach
    arr[L] += a - L*d ;
    arr[R+1] -= a - L*d ;
    drr[L] += d ;
    drr[R+1] -= d ;

*/

void solve()
{
    int q, n;
    cin >> q >> n;
    int a, d, l, r;
    int arr[n + 1] = {0}, drr[n + 1] = {0};
    while (q--)
    {
        cin >> a >> d >> l >> r;
        arr[l] += a - l * d;
        arr[r + 1] -= a - l * d;
        drr[l] += d;
        drr[r + 1] -= d;
    }

    f(i, 1, n)
    {
        arr[i] += arr[i - 1];
        drr[i] += drr[i - 1];
    }

    f(i, 0, n) arr[i] += (i * drr[i]);

    f(i, 0, n) cout << arr[i] << sp;
    cout << el;

    return;
}

void MY_AP()
{
    // take the input and partial sum
    int q, n;
    cin >> q >> n;
    int arr[n + 1] = {0}, drr[n + 1] = {0};
    int a, d, l, r;
    while (q--)
    {
        cin >> a >> d >> l >> r;
        arr[l] += a;
        arr[r + 1] -= a + ((r - l) * d);
        drr[l + 1] += d;
        drr[r + 1] -= d;
    }

    // Calculate the prefix from the partial part
    d = drr[0];
    f(i, 1, n)
    {
        d += drr[i];
        drr[i] = drr[i - 1] + d;
        arr[i] += arr[i - 1];
    }
    f(i, 0, n) arr[i] += drr[i];

    // Output the answer
    f(i, 0, n) cout << arr[i] << sp;
    cout << el;

    return;
}