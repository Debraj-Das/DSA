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

int ar[101][101];
int dp[101][101][12];

void solve()
{
    int n, m, k, t, i, j, l;
    cin >> n >> m >> k;
    string s;
    for (i = 1; i <= n; i++)
    {
        cin >> s;
        l = s.size() + 1;
        for (j = 1; j < l; j++)
        {
            ar[i][j] = s[j - 1] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    for (i = 1; i <= m; i++)
    {
        t = ar[n][i] % k;
        dp[n][i][t] = ar[n][i];
    }

    for (i = n - 1; i; i--)
        for (j = 1; j <= m; j++)
            for (l = 0; l < k; l++)
            {
                if (j > 1 and dp[i + 1][j - 1][l] != -1)
                {
                    t = dp[i + 1][j - 1][l] + ar[i][j];
                    dp[i][j][t % k] = max(dp[i][j][t % k], t);
                }
                if (j < m and dp[i + 1][j + 1][l] != -1)
                {
                    t = dp[i + 1][j + 1][l] + ar[i][j];
                    dp[i][j][t % k] = max(dp[i][j][t % k], t);
                }
            }

    int ans = -1;

    for (i = 1; i <= m; i++)
        ans = max(ans, dp[1][i][0]);

    cout << ans << el;

    return;
}
