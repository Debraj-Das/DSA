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

#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

template <class T> class modulo
{
  private:
    long long mod;

  public:
    modulo(long long md = 1e9 + 7) : mod(md)
    {
    }
    T add(T a, T b)
    {
        a %= mod;
        b %= mod;
        return (a + b + mod) % mod;
    }
    T sub(T a, T b)
    {
        a %= mod;
        b %= mod;
        return (mod + a - b) % mod;
    }
    T mul(T a, T b)
    {
        a %= mod;
        b %= mod;
        return (a * 1LL * b) % mod;
    }
    T exp(T a, long long b)
    {
        a %= mod;
        b %= mod;
        T x;
        for (x = 1; b; a = (1LL * a * a) % mod, b >>= 1)
            x = (x * (a * 1LL * (b & 1) + !(b & 1))) % mod;
        return x;
    }
    T inv(T a)
    {
        a %= mod;
        return exp(a, mod - 2);
    }
    T div(T a, T b)
    {
        a %= mod;
        b %= mod;
        b = exp(b, mod - 2);
        return (a * 1LL * b) % mod;
    }
};

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int t ; cin >> t; while (t--)
    solve();

    return 0;
}

void solve()
{
    modulo<int> m;

    cout << m.add(23, 23) << el;
    cout << m.inv(2) << el;

    return;
}
