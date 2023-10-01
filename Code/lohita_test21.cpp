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

    solve();

    return 0;
}

inline pair<int, bool> digit(const string &s)
{
    int ans = 0, i;
    for (i = 1; s[i] != ' '; i++)
        ans = ans * 10 + (s[i] - '0');

    bool val = (s[i + 1] == 'e');
    ans--;
    return make_pair(ans, val);
}

int countFaults(int n, vector<string> logs)
{
    int ar[n] = {0};
    int ans = 0;
    pair<int, bool> j;
    for (auto &s : logs)
    {
        j = digit(s);
        if (j.second)
        {
            ar[j.first]++;
            if (ar[j.first] == 3)
            {
                ans++;
                ar[j.first] = 0;
            }
        }
        else
        {
            ar[j.first] = 0;
        }
    }

    return ans;
}

void solve()
{
    int n = 32342;

    vector<string> s = {"s1 error", "s2 error",  "s1 error",    "s2 succes", "s1 error",    "s1 error",
                        "s1 error", "s1 sucess", "s3000 error", "s2 error",  "s3000 error", "s3000 error"};

    cout << countFaults(n, s) << '\n';

    return;
}
