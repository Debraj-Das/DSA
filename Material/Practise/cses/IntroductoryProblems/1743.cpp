// Problem: String Reorder
// URL: https://cses.fi/problemset/task/1743
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

    const int n = s.size(), N = 26;
    int freq[N] = {0};
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    string ans;
    pair<int, int> pmax({-1, -1});
    for (int i = 0; i < n; i++) {
        pmax = {-1, -1};

        for (int j = 0; j < N; j++) {
            if (pmax.first <= freq[j]) {
                pmax.second = pmax.first;
                pmax.first = freq[j];
            } else if (pmax.second < freq[j]) {
                pmax.second = freq[j];
            }
        }

        for (int j = 0; j < N; j++) {
            if ((ans.size() > 0 and ans.back() == char(j + 'A')) or
                freq[j] == 0)
                continue;

            int mx = (pmax.first == freq[j] ? pmax.second : pmax.first);
            if (2 * mx > (n - i) or 2 * freq[j] > (n - i + 1)) continue;

            ans.push_back(char(j + 'A'));
            freq[j]--;
            break;
        }
    }

    cout << (ans.size() == 0 ? "-1" : ans);

    return;
}
