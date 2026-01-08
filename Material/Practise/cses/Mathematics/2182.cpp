// Problem: Divisor Analysis
// URL: https://cses.fi/problemset/task/2182
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

ll exp(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }

    ll count = 1;
    for (int i = 0; i < n; i++) {
        count = (count * (ar[i].second + 1)) % mod;
    }

    cout << count << sp;

    ll sum = 1;
    for (int i = 0; i < n; i++) {
        ll ap = (exp(ar[i].first, ar[i].second + 1, mod) - 1 + mod) % mod;
        ll dw = exp(ar[i].first - 1, mod - 2, mod);
        sum = (sum * ap) % mod;
        sum = (sum * dw) % mod;
    }

    cout << sum << sp;

    ll product = 1;
    ll k = 1;
    bool by2 = true;
    for (int i = 0; i < n; i++) {
        if (by2 and ar[i].second % 2 == 1) {
            by2 = false;
            ll m = (ar[i].second + 1) / 2;
            k = (k * m) % (mod - 1);
            continue;
        }
        k = (k * (ar[i].second + 1)) % (mod - 1);
    }

    for (int i = 0; i < n; i++) {
        ll m = (by2 ? ar[i].second / 2 : ar[i].second);
        m = (m * k) % (mod - 1);
        m = exp(ar[i].first, m, mod);
        product = (product * m) % mod;
    }

    cout << product;

    return;
}
