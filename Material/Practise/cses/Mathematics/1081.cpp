// Problem: Common Divisors
// URL: https://cses.fi/problemset/task/1081
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

const int N = 1000001;
int freq[N];

void solve() {
    int n;
    cin >> n;

    memset(freq, 0, sizeof(freq));
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    for (int i = N - 1; i > 1; i--) {
        int fq = 0;
        for (int j = i; j < N; j += i) {
            fq += freq[j];
        }
        if (fq > 1) {
            cout << i;
            return;
        }
    }

    cout << 1;

    return;
}
