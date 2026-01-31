// Problem: Giant Pizza
// URL: https://cses.fi/problemset/task/1684
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

int n, m;

int nag(int x) {
    if (x > m) {
        x -= m;
    } else {
        x += m;
    }
    return x;
}

vector<int> par, sz;

int find(int u) { return par[u] = (par[u] == u ? u : find(par[u])); }

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    return true;
}

void solve() {
    cin >> n >> m;

    sz.assign(2 * m + 1, 1);
    par.assign(2 * m + 1, 0);
    for (int i = 1; i <= 2 * m; i++) {
        par[i] = i;
    }

    for (int i = 0; i < n; i++) {
        char sa, sb;
        int a, b;
        cin >> sa >> a >> sb >> b;
        if (sa == '-') a = nag(a);
        if (sb == '-') b = nag(b);

        int na = nag(a);
        int nb = nag(b);

        merge(na, b);
        merge(nb, a);
    }

    for (int i = 1; i <= m; i++) {
        if (find(i) == find(i + m)) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    vector<int> ans(m + 1, -1);
    for (int i = 1; i <= m; i++) {
        int pt = find(i);
        if (pt > m) {
            int npt = pt - m;
            if (ans[npt] == -1) {
                ans[i] = 0;
                ans[npt] = 1;
            } else {
                ans[i] = 1 - ans[npt];
            }
        } else {
            if (ans[pt] == -1) {
                ans[pt] = ans[i] = 0;
            } else {
                ans[i] = ans[pt];
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) {
            cout << '-' << sp;
        } else {
            cout << '+' << sp;
        }
    }

    return;
}
