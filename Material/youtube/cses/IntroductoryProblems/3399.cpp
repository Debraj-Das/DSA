// Problem: Raab Game I
// URL: https://cses.fi/problemset/task/3399
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
    int n, a, b;
    cin >> n >> a >> b;

    if ((a == 0 and b != 0) or (a != 0 and b == 0) or (a + b > n)) {
        cout << "NO";
        return;
    }

    cout << "YES" << el;
    for (int i = 1; i <= n; i++) {
        cout << i << sp;
    }
    cout << el;

    for (int i = a + 1; i <= a + b; i++) {
        cout << i << sp;
    }
    for (int i = 1; i <= a; i++) {
        cout << i << sp;
    }
    for (int i = a + b + 1; i <= n; i++) {
        cout << i << sp;
    }

    return;
}
