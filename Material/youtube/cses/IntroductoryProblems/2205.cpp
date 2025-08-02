// Problem: Gray Code
// URL: https://cses.fi/problemset/task/2205/
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

void printBits(const bitset<16> &bits, const int &n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << bits[i];
    }
    cout << el;
}

void solve() {
    int n;
    bitset<16> bits;
    cin >> n;

    printBits(bits, n);
    for (int i = 1, lsb; i < (1 << n); i++) {
        lsb = __builtin_ffs(i) - 1;
        bits.flip(lsb);
        printBits(bits, n);
    }

    return;
}
