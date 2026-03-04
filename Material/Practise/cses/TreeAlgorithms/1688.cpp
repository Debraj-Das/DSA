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
    /* cin >> TC; */
    for (int i = 0; i < TC; i++) {
        /* cout<<"case "<<(i+1)<<": "; */
        solve();
        cout << '\n';
    }

    return 0;
}

void dfs(int u, int pp, int lv, vector<int> &level, vector<vector<int>> &gr) {
    level[u] = lv;
    for (int v : gr[u]) {
        if (v == pp)
            continue;
        dfs(v, u, lv + 1, level, gr);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<array<int, 20>> par(n + 1);
    vector<vector<int>> gr(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> par[i][0];
        gr[par[i][0]].push_back(i);
    }

    par[1][0] = -1;
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            int next = par[i][j - 1];
            if (next == -1) {
                par[i][j] = -1;
                continue;
            }
            par[i][j] = par[next][j - 1];
        }
    }

    vector<int> level(n + 1);
    dfs(1, -1, 1, level, gr);

    int x, y;
    while (q--) {
        cin >> x >> y;

		// when level different present, that time equallize the level.
        if (level[x] != level[y]) {
            if (level[x] < level[y])
                swap(x, y);
            int k = level[x] - level[y];
            for (int i = 19; i >= 0; i--) {
                if ((k >> i) & 1) {
					x = par[x][i];
                }
            }
        }

		// when y is ancester of x.
		if(x == y){
			cout<<x<<el;
			continue;
		}

        for (int i = 19; i >= 0; i--) {
            if (par[x][i] != par[y][i]) {
                x = par[x][i];
                y = par[y][i];
            }
        }

        cout << par[x][0] << el;
    }

    return;
}
