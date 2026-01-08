// Problem: Josephus Queries
// URL: https://cses.fi/problemset/task/2164
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

int rec(int n, int k, bool fst) {
    if (n == 1) return 1;
    int r = (n + fst) / 2;
    if (r >= k) return 2 * k - fst;
    return 2 * rec(n - r, k - r, ((n & 1) ? !fst : fst)) - 1 + fst;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC, n, k;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        cout << rec(n, k, 0) << el;
    }

    return 0;
}
