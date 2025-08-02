// Problem: Number Spiral
// URL: https://cses.fi/problemset/task/1071
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
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        solve();
        cout << '\n';
    }

    return 0;
}

void solve() {
    int x, y;
    cin >> x >> y;

    if (x >= y) {
        ll mid = (1ll * x * x - x + 1);
        int red = x - y;
        if (x % 2 == 1) {
            cout << (mid - red);
            return;
        } else {
            cout << (mid + red);
        }
    } else {
        ll mid = (1ll * y * y - y + 1);
        int red = y - x;
        if (y % 2 == 1) {
            cout << (mid + red);
        } else {
            cout << (mid - red);
        }
    }

    return;
}
