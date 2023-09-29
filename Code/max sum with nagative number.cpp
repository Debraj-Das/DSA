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

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;

    int ar[n];
    f(i, 0, n) cin >> ar[i];
    int pref[n];
    pref[0] = ar[0];
    f(i, 1, n) pref[i] = ar[i] + pref[i - 1];
    multiset<int> mt;

    int ans = 0;
    auto it = mt.begin();
    for (int tail = 0, head = 0, odd = 0, sum; tail < n; tail++)
    {
        while (head < n and (odd < k or (ar[head] & 1) == 0))
        {
            odd += ar[head] & 1;
            mt.insert(pref[head]);

            head++;
        }

        // update the answer
        sum = d + eif(tail, pref[tail - 1], 0);
        it = mt.upper_bound(sum);
        if (it != mt.begin())
        {
            it--;
            ans = max(ans, (*it) - sum);
        }
		
		// Remove the tail from the window
        if (tail == head)
        {
            head = tail + 1;
        }
        else
        {
            odd -= ar[tail] & 1;
            auto it = mt.find(pref[tail]);
            if (it != mt.end())
            {
                mt.erase(it);
            }
        }
    }

    // time complexity is O(nlog(n)) and space complexity O(n);

    cout << ans << el;

    return;
}
