// Problem: Counting Coprime Pairs
// URL: https://cses.fi/problemset/task/2417
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
int ar[N], pf[N], ac[N];

void solve() {
    ll n;
    cin >> n;

    memset(ar, 0, sizeof(ar));
    memset(pf, 0, sizeof(pf));
    memset(ac, 0, sizeof(ac));

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ar[x]++;
    }

    ll ans = 0, fq;
    for (int i = 2; i < N; i++) {
        if (ac[i]) continue;

        fq = 0;
        for (int j = i; j < N; j += i) {
            fq += ar[j];
        }

        if (pf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (ac[j]) continue;
                pf[j]++;
                if (j % (1ll * i * i) == 0) ac[j] = 1;
            }
        }

        fq = (fq * (fq - 1)) / 2;
        ans += (pf[i] % 2 ? fq : -fq);
    }

    cout << ((n * (n - 1)) / 2) - ans;

    return;
}
