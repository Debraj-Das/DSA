#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const ll INF = 1ll * mod * mod;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
#define setpr(x) cout << setprecision(x) << fixed

// clang-format off
std::mt19937 random_number_generator(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rng(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(random_number_generator); }
// clang-format on

inline double rdd(int l = 0, int r = 100000) {
    double ans = rng(1000, 1000 * r);
    return ans / 1000;
}

// shuffle(v.begin(), v.end(), rng);  // shuffle syntex

const string a = "abcdefghijklmnopqrstuvwxyz";
const string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num = "0123456789";
const string spec = "!@#$%^&*";

inline char rdc() {
    const string source = a;
    const int n = source.size() - 1;

    return source[rng(0, n)];
}

void text(int len) {
    const string source = a + A + num + spec;
    const int n = source.size() - 1;

    while (len--) {
        cout << source[rng(0, n)];
    }
    cout << el;
    return;
}

void arr(const int n, const int l = 0, const int r = 1e9) {
    for (int i = 0; i < n; i++) {
        cout << rng(l, r) << sp;
    }
    cout << el;
    return;
}

void distinctElements(const int n, const int l = 0, const int r = 1e9) {
    set<int> used;
    for (int i = 0, x; i < n; i++) {
        do {
            x = rng(l, r);
        } while (used.count(x));

        cout << x << sp;
        used.insert(x);
    }
    cout << el;
    return;
}

void tree(int n) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) {
        edges.emplace_back(rng(1, i - 1), i);
    }

    shuffle(edges.begin(), edges.end(), random_number_generator);
    for (pair<int, int> &e : edges) {
        if (rng() % 2) {
            swap(e.first, e.second);
        }
        cout << e.first << sp << e.second << el;
    }
    return;
}

void graph(const int n, const int m) {
    set<pair<int, int>> st;
    int u, v;
    for (int i = 0; i < m; i++) {
        do {
            u = rng(1, n - 1);
            v = rng(u + 1, n);
        } while (st.count(make_pair(u, v)));

        st.insert(make_pair(u, v));

        if ((u + v) & 1) {
            swap(u, v);
        }
        cout << u << sp << v << el;
    }

    st.clear();
    return;
}

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC = 1;
    /* cout << TC << el; */
    while (TC--) {
        solve();
        cout << el;
    }

    return 0;
}

void solve() { return; }
