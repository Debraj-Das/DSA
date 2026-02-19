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

struct iset {
  private:
    int n;
    int sz;
    vector<long long> tr;
    vector<int> ar;
    void update(int k, int v) {
        for (; k <= n; k += (k & -k)) {
            tr[k] += v;
        }
    }
    long long sum(int k) {
        long long s = 0;
        for (; k > 0; k -= (k & -k)) {
            s += tr[k];
        }
        return s;
    }

  public:
    iset(int _n) : n(_n) {
        sz = 0;
        tr.assign(n + 1, 0LL);
        ar.assign(n + 1, 0);
    }
    int size() { return sz; }
    int capacity() { return n; }
    void insert(int x) {
        if (ar[x] > 0)
            return;
        update(x, 1);
        ar[x]++;
        sz++;
    }
    void erase(int x) {
        if (ar[x] < 1)
            return;
        update(x, -1);
        ar[x]--;
        sz--;
    }
    int find_by_order(int id) {
        if (id < 0 or id > sz) {
            return -1;
        }
		int p = 0, sum = 0;
		for(int i = (1<<31); i > 0; i >>= 1){
			int np = p + i;
			if(np <= n and sum + tr[np] < id){
				p = np;
				sum += tr[np];
			}
		}
        return p+1;
    }

    int order_of_key(int x) {
        if (x > n)
            return -1;
        return sum(x);
    }
};

constexpr int op = 4;
constexpr int n = 1000000;

void solve() {
    iset st(n);
    bool ch = true;
    int ty, x;
    while (ch) {

		cin>>ty;
		if(ty > op){
			break;
		}
        cin >> x;

        switch (ty) {
        case 1: {
            st.insert(x);
            break;
        }
        case 2: {
            st.erase(x);
            break;
        }
        case 3: {
            cout << st.find_by_order(x) << endl;
            break;
        }
        case 4: {
            cout << st.order_of_key(x) << endl;
            break;
        }
        default: {
            ch = false;
            break;
        }
        }
    }

    return;
}
