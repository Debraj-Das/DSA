// Problem: Palindrome Reorder
// URL: https://cses.fi/problemset/task/1755
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

void solve() {
    string s;
    cin >> s;

    bool liveLine = (s.size() & 1) ? true : false;
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    for (int i : freq) {
        if (i & 1) {
            if (liveLine) {
                liveLine = false;
            } else {
                cout << "NO SOLUTION";
                return;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 1; 2 * j <= freq[i]; j++) {
            cout << char('A' + i);
        }
    }

    if (s.size() & 1) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                cout << char('A' + i);
                break;
            }
        }
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 1; 2 * j <= freq[i]; j++) {
            cout << char('A' + i);
        }
    }

    return;
}
