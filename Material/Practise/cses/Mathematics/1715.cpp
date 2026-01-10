// Problem: Creating Strings II
// URL: https://cses.fi/problemset/task/1715
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

ll invf(ll a) {
    ll b = mod - 2;
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    const int n = s.size();

    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (char c : s) {
        freq[c - 'a']++;
    }

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (1ll * i * fac[i - 1]) % mod;
    }

    ll ans = fac[n];
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;
        ans = (ans * invf(fac[freq[i]])) % mod;
    }

    cout << ans;

    return;
}
