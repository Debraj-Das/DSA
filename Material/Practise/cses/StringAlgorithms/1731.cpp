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

struct Node {
    constexpr static int N = 26;
    Node *child[N];
    int prefix;
    int wend;
    Node() {
        for (int i = 0; i < N; i++) {
            child[i] = nullptr;
        }
        prefix = 0;
        wend = 0;
    }
};

struct Trie {
    Node *root;
    Trie() { root = new Node(); }
    void insert(const string &s) {
        Node *cur = root;
        cur->prefix++;
        for (size_t i = 0; i < s.size(); i++) {
            int id = s.at(i) - 'a';
            if (cur->child[id] == nullptr) {
                cur->child[id] = new Node();
            }
            cur = cur->child[id];
            cur->prefix++;
        }
        cur->wend++;
        return;
    }
} tree;

constexpr int mod = 1e9 + 7;
int dp[5000];

int rec(size_t id, const string &s) {
    /* cout<<id<<el; */
    if (id == s.size()) {
        return 1;
    }
    if (dp[id] != -1) {
        return dp[id];
    }

    int ans = 0;

    Node *cur = tree.root;
    for (size_t j = id; j < s.size(); j++) {
        /* cout<<j<<sp<<s.at(j)<<el; */
        int i = s.at(j) - 'a';
        if (cur->child[i] == nullptr or cur->child[i]->prefix == 0) {
            /* cout<<i<<sp<<j<<el; */
            break;
        }
        cur = cur->child[i];
        if (cur->wend > 0) {
            ans = (ans + rec(j + 1, s)) % mod;
        }
    }

    return dp[id] = ans;
}

void solve() {
    string s;
    cin >> s;
    /* cout<<s<<el; */

    int k;
    cin >> k;
    string t;
    for (int i = 0; i < k; i++) {
        cin >> t;
        tree.insert(t);
    }

    memset(dp, -1, sizeof(dp));
    int ans = rec(0, s);

    cout << ans;

    return;
}
