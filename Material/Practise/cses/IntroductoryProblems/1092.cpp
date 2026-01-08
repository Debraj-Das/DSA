// Problem: Two Sets
// URL: https://cses.fi/problemset/task/1092
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

    if (n % 4 == 1 or n % 4 == 2) {
        cout << "NO";
        return;
    }

    if (n % 4 == 0) {
        cout << "YES" << el;
        cout << (n / 2) << el;
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 0 or i % 4 == 1) {
                cout << i << sp;
            }
        }
        cout << el << (n / 2) << el;
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 3 or i % 4 == 2) {
                cout << i << sp;
            }
        }
    }

    if (n % 4 == 3) {
        cout << "YES" << el;
        cout << ((n - 3) / 2) + 2 << el;
        cout << 1 << sp << 2 << sp;

        for (int i = 4; i <= n; i++) {
            if (i % 4 == 0 or i % 4 == 3) {
                cout << i << sp;
            }
        }
        cout << el << ((n - 3) / 2) + 1 << el;

        cout << 3 << sp;
        for (int i = 4; i <= n; i++) {
            if (i % 4 == 1 or i % 4 == 2) {
                cout << i << sp;
            }
        }
    }

    return;
}
