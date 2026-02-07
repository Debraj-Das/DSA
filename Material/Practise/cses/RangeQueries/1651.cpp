// Problem: Range Update Queries
// URL: https://cses.fi/problemset/task/1651/
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
#define int long long

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

/*
   Description:
      Zero-indexed max-tree.
      Bounds are inclusive to the left and exclusive to the right.
      Can be changed by modifying T, f and unit.
*/

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }  // (any associative fn)
    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) {  // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    Tree sg(n + 1);
    vector<int> par(n + 1, 0);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            par[a] += u;
            par[b] -= u;
            sg.update(a, par[a]);
            sg.update(b, par[b]);
        } else {
            int x;
            cin >> x;
            cout << ar[x - 1] + sg.query(0, x) << el;
        }
    }

    return;
}
