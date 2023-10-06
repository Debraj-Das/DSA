// Problem: H2. Maximum Crossings (Hard Version)
// URL: https://codeforces.com/contest/1676/problem/H2
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

long long merge(int a[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = temp[i];
    return count;
}
long long mergeSort(int a[], int temp[], int left, int right)
{
    int mid;
    long long count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        count = mergeSort(a, temp, left, mid);
        count += mergeSort(a, temp, mid + 1, right);
        count += merge(a, temp, left, mid + 1, right);
    }
    return count;
}
long long aInversion(int a[], int n)
{
    int temp[n];
    return mergeSort(a, temp, 0, n - 1);
}

void solve()
{
    int n;
    cin >> n;

    int ar[n];

    f(i, 0, n) cin >> ar[i];

    long long res = aInversion(ar, n);
    sort(ar, ar + n);
    long long curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (ar[i] != ar[i - 1])
        {
            res += (curr * (curr - 1)) / 2;
            curr = 1;
        }
        else
        {
            curr++;
        }
    }

    res += (curr * (curr - 1)) / 2;
    cout << res << el;

    return;
}
