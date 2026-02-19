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
const int mod = 1e9 + 7;
const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))

ll binary(ll lo, ll hi, function<bool(ll)> check) {
    ll ans = hi + 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

ll LCM[262145];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    int ar[n];
    rep(i, 0, n) cin >> ar[i];

    const int N = (1 << n);
    ll x;
    for (int i = 1, j; i < N; i++) {
        for (j = 0, x = 1; j < 18; j++) {
            if (i & (1 << j))
                x = (x * ar[j]) / __gcd(x, (ll)ar[j]);
        }
        if (__builtin_popcount(i) % 2 == 0)
            x *= (-1);
        LCM[i] = x;
    }

    x = binary(0L, 1e18L, [&](ll mid) {
        ll cot = 0;
        for (int i = 1; i < N; i++) {
            cot += (mid / LCM[i]);
        }
        return cot >= k;
    });

    cout << x;

    return 0;
}
