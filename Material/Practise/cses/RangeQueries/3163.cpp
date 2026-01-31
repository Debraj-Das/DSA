// Problem: Range Interval Queries (Optimized MST)
// Approach: Layered Merge Sort Tree (Static Arrays)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const char el = '\n';
const int N = 200005;
const int LOGN = 19;  // 2^18 > 200,000

int ar[N];
// tree[depth][index]: Stores the sorted values for that level
int t[LOGN][N];

int n, q;

// Build is now O(N log N) but purely array operations
void build(int dep, int l, int r) {
    if (l == r) {
        t[dep][l] = ar[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(dep + 1, l, mid);
    build(dep + 1, mid + 1, r);

    // Merge the two sorted children (from depth + 1) into current depth
    // This is essentially doing one step of Merge Sort
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (t[dep + 1][i] < t[dep + 1][j])
            t[dep][k++] = t[dep + 1][i++];
        else
            t[dep][k++] = t[dep + 1][j++];
    }
    while (i <= mid) t[dep][k++] = t[dep + 1][i++];
    while (j <= r) t[dep][k++] = t[dep + 1][j++];
}

// Query is O(log^2 N) but with very low constants
int query(int dep, int l, int r, int lq, int rq, int mn, int mx) {
    if (l > rq || r < lq) return 0;

    // If fully inside range, binary search on the pre-sorted array at this
    // depth
    if (l >= lq && r <= rq) {
        // Pointer arithmetic for speed
        int* start = t[dep] + l;
        int* end = t[dep] + r + 1;

        // Count elements <= mx
        int* ub = upper_bound(start, end, mx);
        // Count elements < mn
        int* lb = lower_bound(start, end, mn);

        return (ub - lb);
    }

    int mid = (l + r) >> 1;
    return query(dep + 1, l, mid, lq, rq, mn, mx) +
           query(dep + 1, mid + 1, r, lq, rq, mn, mx);
}

void solve() {
    if (!(cin >> n >> q)) return;

    for (int i = 0; i < n; i++) cin >> ar[i];

    build(0, 0, n - 1);

    int lq, rq, mn, mx;
    while (q--) {
        cin >> lq >> rq >> mn >> mx;
        // 0-based indexing adjustments
        // query(0, 0, n - 1, lq - 1, rq - 1, mn, mx);
        cout << query(0, 0, n - 1, lq - 1, rq - 1, mn, mx) << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}