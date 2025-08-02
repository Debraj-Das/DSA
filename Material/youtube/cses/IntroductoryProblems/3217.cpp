// Problem: Knight Moves Grid
// URL: https://cses.fi/problemset/task/3217
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

const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1},  {2, 1},
                                      {-1, 2},  {1, 2},  {-1, -2}, {1, -2}};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    grid[0][0] = 0;
    queue<array<int, 3>> st;
    st.push({0, 0, 0});

    while (st.size()) {
        array<int, 3> cur = st.front();
        st.pop();
        for (pair<int, int> move : moves) {
            int x = cur[0] + move.first;
            int y = cur[1] + move.second;
            if (x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == -1) {
                grid[x][y] = cur[2] + 1;
                st.push({x, y, cur[2] + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << sp;
        }
        cout << el;
    }

    return;
}
