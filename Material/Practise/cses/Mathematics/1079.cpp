// Problem: Binomial Coefficients
// URL: https://cses.fi/problemset/task/1079
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

const int mod = 1e9 + 7;
const int N = 1000001;
int fact[N], invf[N];

void cal() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    }
    ll ans = 1;
    int b = mod - 2;
    ll a = fact[N - 1];
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    invf[N - 1] = ans;
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = (1ll * invf[i + 1] * (i + 1)) % mod;
    }
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cal();
    int TC = 1;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        solve();
        cout << '\n';
    }

    return 0;
}

void solve() {
    int n, r;
    cin >> n >> r;

    ll ans = fact[n];
    ans = (ans * invf[r]) % mod;
    ans = (ans * invf[n - r]) % mod;

    cout << ans;

    return;
}
