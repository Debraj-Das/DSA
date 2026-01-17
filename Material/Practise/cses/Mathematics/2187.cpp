// Problem: Bracket Sequences II
// URL: https://cses.fi/problemset/task/2187
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

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[N], inf[N];

ll ncr(int n, int r) {
    if (r < 0 or n < r) return 0;
    ll ans = fact[n];
    ans = (ans * inf[n - r]) % mod;
    ans = (ans * inf[r]) % mod;
    return ans;
};

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n & 1) {
        cout << (0);
        return;
    }

    int bal = 0;
    int p = n / 2, q = n / 2;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            bal++;
            p--;
        } else {
            bal--;
            q--;
        }

        if (bal < 0) {
            cout << 0;
            return;
        }
    }

    int n2 = n - s.size();

    // (n2)C(p) - (n2)C(p-1);

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    }

    ll ans = 1;
    ll a = fact[N - 1];
    ll b = mod - 2;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }

    inf[N - 1] = ans;

    for (int i = N - 2; i >= 0; i--) {
        inf[i] = (1ll * inf[i + 1] * (i + 1)) % mod;
    }

    // cerr << n2 << sp << p << sp << q << el;

    ans = ncr(n2, p);

    // cerr << ans << sp << ncr(n2, p - 1) << el;

    ans = (ans - ncr(n2, p - 1) + mod) % mod;

    cout << ans;

    return;
}
