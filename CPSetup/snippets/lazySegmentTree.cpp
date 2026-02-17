struct Seg {
    vector<ll> tr;
	vector<ll> lazy;
	vector<bool> isLazy;

    ll f(ll a, ll b) { return a + b; }
	void lazyAssign(int id, int l, int r, ll lz){
		isLazy[id] = true;
		lazy[id] += lz;
		return;
	}
	void push(int id, int l ,int r){
		if(isLazy[id] == false) return;
		tr[id] += (r - l+1)*lazy[id];
		if(l != r){
			int mid = l + (r-l)/2;
			lazyAssign(2*id, l, mid, lazy[id]);
			lazyAssign(2*id+1, mid+1, r, lazy[id]);
		}
		isLazy[id] = false;
		lazy[id] = 0;
	}

    Seg(vector<int> &ar) {
        const int k = 4 * (ar.size());
        tr.assign(k, 0);
		isLazy.assign(k, 0);
		lazy.assign(k, 0);
        build(1, 0, ar.size() - 1, ar);
    }

    void build(int id, int l, int r, const vector<int> &ar) {
        if (l == r) {
            tr[id] = ar[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * id, l, mid, ar);
        build(2 * id + 1, mid + 1, r, ar);
        tr[id] = f(tr[2 * id], tr[2 * id + 1]);
    }

    void update(int id, int l, int r, int lq, int rq, int v) {
		push(id, l, r);
		if(lq > r or rq < l) return;

		if(lq <= l and r <= rq){
			lazyAssign(id, l, r, v);
			push(id, l, r);
			return;
		}

        int mid = l + (r - l) / 2;
        update(2 * id, l, mid, lq, rq, v);
        update(2 * id + 1, mid + 1, r, lq, rq, v);
        tr[id] = f(tr[2 * id], tr[2 * id + 1]);
        return;
    }

    ll query(int id, int l, int r, int lq, int rq) {
		push(id,l, r);
        if (lq > r or rq < l) return 0;
        if (lq <= l and r <= rq) return tr[id];
        int mid = l + (r - l) / 2;
        return f(query(2 * id, l, mid, lq, rq),
                 query(2 * id + 1, mid + 1, r, lq, rq));
    }
};

