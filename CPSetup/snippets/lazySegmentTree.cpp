/**
 * Description: Iterative Segment Tree with Lazy Propagation using Boolean Flag
 for Associative opertion
 * Operations: Range Assignment (Set [L, R) = Val), Range Max Query (Get [L, R)
 value)

 * T : Type for tree nodes (Values)
 * L : Type for lazy updates (Assignment value)

 * * only need to modify these 4 things:
  * 1. unit (Identity for merge)
  * 2. merge (Combine children)
  * 3. mapping (Apply lazy to node)
  * 4. composition (Combine lazy tags)

 */

template <class T = int, class L = int>
struct LazyTree {
    const T unit = numeric_limits<T>::lowest();
    T merge(T a, T b) { return max(a, b); }
    T mapping(T node, L val, int len) { return val; }
    L composition(L new_val, L old_val) { return new_val; }

    int n, h;
    vector<T> s;
    vector<L> d;
    vector<bool> lazy;
    vector<int> sz;
    LazyTree(int n = 0, T def = 0)
        : n(n), s(2 * n, def), d(n), lazy(n, false), sz(2 * n, 0) {
        if (n == 0) return;
        h = sizeof(int) * 8 - __builtin_clz(n);
        for (int i = 0; i < n; i++) sz[n + i] = 1;
        for (int i = n - 1; i > 0; i--) sz[i] = sz[2 * i] + sz[2 * i + 1];
        for (int i = n - 1; i > 0; i--) s[i] = merge(s[2 * i], s[2 * i + 1]);
    }
    LazyTree(const vector<T>& v)
        : n(v.size()),
          s(2 * v.size()),
          d(v.size()),
          lazy(v.size(), false),
          sz(2 * v.size(), 0) {
        if (n == 0) return;
        h = sizeof(int) * 8 - __builtin_clz(n);
        for (int i = 0; i < n; i++) {
            s[n + i] = v[i];
            sz[n + i] = 1;
        }
        for (int i = n - 1; i > 0; i--) {
            s[i] = merge(s[2 * i], s[2 * i + 1]);
            sz[i] = sz[2 * i] + sz[2 * i + 1];
        }
    }

    void apply(int p, L val) {
        s[p] = mapping(s[p], val, sz[p]);
        if (p < n) {
            if (lazy[p]) {
                d[p] = composition(val, d[p]);
            } else {
                d[p] = val;
                lazy[p] = true;
            }
        }
    }

    void build(int p) {
        while (p > 1) {
            p >>= 1;
            T combined = merge(s[2 * p], s[2 * p + 1]);
            if (lazy[p]) {
                s[p] = mapping(combined, d[p], sz[p]);
            } else {
                s[p] = combined;
            }
        }
    }

    void push(int p) {
        for (int s_h = h; s_h > 0; --s_h) {
            int i = p >> s_h;
            if (i == 0) continue;
            if (lazy[i]) {
                apply(2 * i, d[i]);
                apply(2 * i + 1, d[i]);
                lazy[i] = false;
            }
        }
    }

    void modify(int l, int r, L val) {
        if (l >= r) return;
        l += n;
        r += n;
        int l0 = l, r0 = r;
        push(l0);
        push(r0 - 1);
        for (; l < r; l /= 2, r /= 2) {
            if (l % 2) apply(l++, val);
            if (r % 2) apply(--r, val);
        }
        build(l0);
        build(r0 - 1);
    }

    T query(int l, int r) {
        if (l >= r) return unit;
        l += n;
        r += n;
        push(l);
        push(r - 1);

        T ra = unit, rb = unit;
        for (; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = merge(ra, s[l++]);
            if (r % 2) rb = merge(s[--r], rb);
        }
        return merge(ra, rb);
    }
};