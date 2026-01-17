// Problem: Permutation Rounds
// URL: https://cses.fi/problemset/task/3398
// Memory Limit: 512 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';

inline void solve();

const int N = 200005;
int prime[N];

void calc() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (prime[i]) continue;
        for (int j = i; j < N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    calc();
    int TC = 1;
    // cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        solve();
        cout << '\n';
    }

    return 0;
}

int rec(int u, const vector<int> &ar, vector<bool> &vis) {
    if (vis[u]) return 0;
    vis[u] = true;
    return 1 + rec(ar[u], ar, vis);
}

const int mod = 1e9 + 7;
int exp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    // r1, r2, ..., r_i, ..., r_n => lcm of all r_i => that will be answer
    map<int, int> ft;
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int r = rec(i, ar, vis);
        map<int, int> mp;
        while (r > 1) {
            mp[prime[r]]++;
            r /= prime[r];
        }

        for (auto &p : mp) {
            ft[p.first] = max(ft[p.first], p.second);
        }
    }

    int ans = 1;
    for (auto &p : ft) {
        int pw = exp(p.first, p.second);
        ans = (1ll * ans * pw) % mod;
    }

    cout << ans;

    return;
}
