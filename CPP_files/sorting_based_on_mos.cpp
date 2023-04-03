#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;

int a[N];

struct query {
	int l, r, ans, id, block;
	bool operator< (query P) const {
		return make_pair(this->block, this->r) < make_pair(P.block, P.r);
	}
} q[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, queries;

	cin >> n;
	m = sqrt(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> queries;

	for (int i = 0; i < queries; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l--; q[i].r--;
		q[i].id = i, q[i].block = q[i].l / m;
	}

	sort(q, q + queries);

	for (int i = 0; i < queries; i++) {
		cout << q[i].id << " " << q[i].l << " " << q[i].r << '\n';
	}










	return 0;
}