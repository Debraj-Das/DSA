// Problem: Visible Buildings Queries
// Optimization: Segment Tree without Vectors

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char el = '\n';
const char sp = ' ';
using pi = pair<int, int>;

const int N = 100005;
int ar[N];
int tree_max[4 * N];
int tree_count[4 * N];
int n, q;

int calc(int id, int l, int r, int limit) {
    if (tree_max[id] <= limit) return 0;
    if (l == r) return 1;

    int mid = l + (r - l) / 2;
    if (tree_max[2 * id] <= limit) {
        return calc(2 * id + 1, mid + 1, r, limit);
    } else {
        return calc(2 * id, l, mid, limit) +
               (tree_count[id] - tree_count[2 * id]);
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        tree_max[id] = ar[l];
        tree_count[id] = 1;
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    tree_max[id] = max(tree_max[2 * id], tree_max[2 * id + 1]);
    int right_contribution = calc(2 * id + 1, mid + 1, r, tree_max[2 * id]);
    tree_count[id] = tree_count[2 * id] + right_contribution;
}

pi query(int id, int l, int r, int lq, int rq, int limit) {
    if (lq > r or rq < l) return {0, -1};

    if (lq <= l and r <= rq) {
        int cnt = calc(id, l, r, limit);
        return {cnt, tree_max[id]};
    }

    int mid = l + (r - l) / 2;
    pi left_res = query(2 * id, l, mid, lq, rq, limit);
    int current_limit = max(limit, left_res.second == -1 ? 0 : left_res.second);

    pi right_res = query(2 * id + 1, mid + 1, r, lq, rq, current_limit);

    int total_count = left_res.first + right_res.first;
    int max_val = max(left_res.second == -1 ? 0 : left_res.second,
                      right_res.second == -1 ? 0 : right_res.second);

    return {total_count, max_val};
}

void solve() {}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1);

    int lq, rq;
    while (q--) {
        cin >> lq >> rq;
        cout << query(1, 0, n - 1, lq - 1, rq - 1, 0).first << el;
    }

    return 0;
}