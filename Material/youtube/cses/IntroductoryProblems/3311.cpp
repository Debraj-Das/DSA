// Problem: Grid Coloring I
// URL: https://cses.fi/problemset/task/3311
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
    int r, c;
    cin >> r >> c;
    string s[r];
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    bool present[4] = {0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            memset(present, 0, sizeof(present));
            if (i > 0) present[s[i - 1][j] - 'A'] = true;
            if (j > 0) present[s[i][j - 1] - 'A'] = true;
            present[s[i][j] - 'A'] = true;

            for (int k = 0; k < 4; k++) {
                if (present[k] == false) {
                    cout << char(k + 'A');
                    s[i][j] = char(k + 'A');
                    break;
                }
            }
        }
        cout << el;
    }

    return;
}
