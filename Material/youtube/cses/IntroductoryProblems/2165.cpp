// Problem: Tower of Hanoi
// URL: https://cses.fi/problemset/task/2165
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

void rec(int f, int s, int t, int n, vector<pair<int, int>> &ans) {
    if (n == 1) {
        ans.push_back({f, t});
        return;
    }

    rec(f, t, s, n - 1, ans);
    ans.push_back({f, t});
    rec(s, f, t, n - 1, ans);
    return;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ans;
    rec(1, 2, 3, n, ans);

    cout << ans.size() << el;
    for (auto &p : ans) {
        cout << p.first << sp << p.second << el;
    }

    return;
}
