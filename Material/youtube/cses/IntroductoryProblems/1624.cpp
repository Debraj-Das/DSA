// Problem: Chessboard and Queens
// URL: https://cses.fi/problemset/task/1624
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

typedef bitset<8> bits;

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

const int N = 8;
int ans = 0;
string s[N];

void rec(int ind, bits stright, bits left, bits right) {
    if (ind == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (s[ind][i] == '*' or stright[i] or left[i] or right[i]) {
            continue;
        }
        stright.set(i, 1);
        left.set(i, 1);
        right.set(i, 1);
        rec(ind + 1, stright, left >> 1, right << 1);
        stright.set(i, 0);
        left.set(i, 0);
        right.set(i, 0);
    }

    return;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    bits stright = 0;
    bits left = 0;
    bits right = 0;

    rec(0, stright, left, right);
    cout << ans;

    return;
}
