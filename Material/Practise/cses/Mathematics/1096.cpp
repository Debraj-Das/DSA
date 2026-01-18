// Problem: Throwing Dice
// URL: https://cses.fi/problemset/task/1096
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

const int mod = 1e9 + 7;

struct mat {
    int n;
    vector<vector<ll>> m;
    mat(int _n) : n(_n) { m.assign(n, vector<ll>(n, 0)); }

    mat operator*(mat &ot) {
        mat ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll sum = 0;
                for (int k = 0; k < n; k++) {
                    sum = (sum + m[i][k] * ot.m[k][j]) % mod;
                }
                ans.m[i][j] = sum;
            }
        }
        return ans;
    }

    mat exp(ll b) {
        mat ans(n);
        for (int i = 0; i < n; i++) {
            ans.m[i][i] = 1;
        }

        mat a = *this;
        while (b) {
            if (b & 1) ans = (ans * a);

            a = (a * a);
            b >>= 1;
        }
        return ans;
    }
};

void solve() {
    ll n;
    cin >> n;

    if (n < 7) {
        cout << (1 << (n - 1));
        return;
    }

    mat fb(6);
    for (int i = 0; i < 6; i++) {
        fb.m[0][i] = 1;
    }

    for (int i = 1; i < 6; i++) {
        fb.m[i][i - 1] = 1;
    }

    mat ans = fb.exp(n - 6);

    ll sum = 0;
    for (int i = 0; i < 6; i++) {
        sum = (sum + ((1 << (5 - i)) * ans.m[0][i]) % mod) % mod;
    }

    cout << sum;

    return;
}
