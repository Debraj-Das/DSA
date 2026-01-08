// Problem: Digit Queries
// URL: https://cses.fi/problemset/task/2431
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC, c;
    long long k, a, b, x;
    cin >> TC;
    while (TC--) {
        cin >> k;
        k--;
        a = 1, b = 9, c = 1;
        while (k >= (b - a + 1) * c) {
            k -= (b - a + 1) * c;
            a *= 10;
            b = (b * 10) + 9;
            c++;
        }

        x = a + k / c;
        cout << to_string(x)[k % c] << '\n';
    }

    return 0;
}