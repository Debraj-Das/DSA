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

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct randomString
{
    std::string s;
    int n;

    randomString(std::string s = "abcdefghijklmnopqrstuvwxyz")
    {
        this->s = s;
        this->n = s.size() - 1;
    }

    int rdi()
    {
        return std::uniform_int_distribution<int>(0, n)(rng);
    }

    char rdc()
    {
        return s[rdi()];
    }

    std::string rds(size_t length)
    {
        std::string ans(length, 0);
        for (size_t i = 0; i < length; i++)
            ans[i] = s[rdi()];

        return ans;
    }
};

/*
    Add this line before used it if it is not present
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    randomString rc("()?");
    rc.rds(10) -> 10 length string made by "()?"
    rc.rdc() -> random char from "()?"
*/

pii cal(vi &v)
{
    if (v.size() == 0)
        return mp(0, 1);

    int len = 0;
    map<int, int> m;
    const int n = v.size();

    f(i, 0, n)
    {
        if (v[i] == 0)
        {
            len = max(len, i + 1);
            continue;
        }

        if (m.find(v[i] + 1) != m.end())
        {
            len = max(len, i - m[v[i] + 1] + 1);
        }

        if (m.find(v[i]) == m.end())
            m[v[i]] = i;
    }

    if (len == 0)
        return make_pair(0, 1);

    int freq = 0;
    f(i, 0, n - len + 1)
    {
        if (v[i] == v[i + len - 1] + 1)
            freq++;
    }

    dstl(v);
    pr(len, freq);

    return make_pair(len, freq);
}

void solve()
{
    // randomString rs("()");
    // string s = rs.rds(10);
    // cerr << s << el;

    string s;
    cin >> s;

    pii ans = mp(0, 1), temp;
    vi v;
    int sum = 0;
    F(&c, s)
    {
        if (c == '(')
            sum++;
        else
            sum--;

        if (sum < 0)
        {
            sum = 0;
            temp = cal(v);
            v.resize(0);

            if (temp.ff > ans.ff)
                ans = temp;
            else if (temp.ff == ans.ff)
                ans.ss += temp.ss;
        }
        else
        {
            v.pb(sum);
        }
    }

    temp = cal(v);
    if (temp.ff > ans.ff)
        ans = temp;
    else if (temp.ff == ans.ff)
        ans.ss += temp.ss;

    cout << ans.ff << sp << eif(ans.ff == 0, 1, ans.ss) << el;

    return;
}
