// Problem: Bracket Sequences I
// URL: https://cses.fi/problemset/task/2064
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        solve();
        cout << '\n';
    }

    return 0;
}

const int mod = 1e9 + 7;

int inv(int a) {
    int b = mod - 2;
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

    if (n & 1) {
        cout << 0;
        return;
    }

    n /= 2;

    int fc = 1;
    for (int i = 1; i <= n; i++) {
        fc = (1ll * fc * i) % mod;
    }

    int inn = inv(fc);
    int inn_1 = inv((1ll * fc * (n + 1)) % mod);

    for (int i = n + 1; i <= 2 * n; i++) {
        fc = (1ll * fc * i) % mod;
    }

    fc = (1ll * fc * inn) % mod;
    fc = (1ll * fc * inn_1) % mod;

    cout << fc;

    return;
}
