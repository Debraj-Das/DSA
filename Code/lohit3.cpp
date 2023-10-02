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

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

int every(int l, int r, vector<int> &tag)
{
    map<int, int> mp;
    for (int i = l - 1; i < r; i++)
        mp[tag[i]]++;

    int ans = 0;
    for (auto &v : mp)
    {
        ans += v.second / 2;
    }

    return ans;
}

vector<int> countPairs(vector<int> &tag, vector<vector<int>> &queries)
{
    vector<int> ans;

    for (auto &v : queries)
    {
        ans.push_back(every(v[0], v[1], tag));
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi ar(n);
    f(i, 0, n) cin >> ar[i];

    int q, x, y;
    cin >> q;
    V<vi> qu(q, vi(2));
    f(i, 0, q)
    {
        cin >> x >> y;
        qu[i][0] = x;
        qu[i][1] = y;
    }

    vi ans = countPairs(ar, qu);
    F(&v, ans)
    cout << v << el;

    return;
}
