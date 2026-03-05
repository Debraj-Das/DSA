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

constexpr int N = 61;
ll pb[N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pb[0] = 0;
    ll pw = 1;
    for (int i = 1; i < N; i++) {
        pb[i] = 2 * pb[i - 1] + pw;
        pw *= 2;
    }

    int TC = 1;
    /* cin >> TC; */
    for (int i = 0; i < TC; i++) {
        /* cout<<"case "<<(i+1)<<": "; */
        solve();
        cout << '\n';
    }

    return 0;
}

ll rec(ll n) {
    if (n <= 0)
        return 0;
    int m = N - 1;
    while (m >= 0 and n < ((1LL << m) - 1)) {
        m--;
    }
    ll rem = n - ((1LL << m) - 1);
    return pb[m] + rem + rec(rem - 1);
}

void solve() {
    ll n;
    cin >> n;

    cout << rec(n) + 3;

    return;
}
