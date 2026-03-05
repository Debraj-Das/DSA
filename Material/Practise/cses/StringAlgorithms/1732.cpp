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

void solve() {
    string s;
    cin >> s;

    const int n = s.size();
    vector<int> lsp(n + 1);
    lsp[0] = -1;
    int i = 0, j = -1;
    while (i < n - 1) {
        while (j != -1 and s.at(i) != s.at(j))
            j = lsp[j];
        i++;
        j++;
        lsp[i] = j;
    }

    vector<int> ans;
    while (j != -1) {
        if (s.at(i) == s.at(j)) {
            ans.push_back(j + 1);
        }
        j = lsp[j];
    }

    reverse(ans.begin(), ans.end());
    for (int p : ans) {
        cout << p << sp;
    }

    return;
}
