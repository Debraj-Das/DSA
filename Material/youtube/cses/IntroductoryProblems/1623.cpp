// Problem: Apple Division
// URL: https://cses.fi/problemset/task/1623
// Memory Limit: 512 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

void solve() {
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll ans = accumulate(ar, ar + n, 0ll);
    for (int i = 0; i < (1 << n); i++) {
        ll diff = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                diff += ar[j];
            } else {
                diff -= ar[j];
            }
        }
        ans = min(ans, abs(diff));
    }

    cout << ans;

    return;
}
