#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

vector<int> subsetsums(vector<int> a) {

	int n = a.size();
	vector<int> result;

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) sum += a[j];
		}
		result.push_back(sum);
	}

	return result;

}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> left, right;

	for (int i = 0; i < n; i++) {
		if (i <= n / 2) left.push_back(v[i]);
		else right.push_back(v[i]);
	}

	vector<int> left_sums = subsetsums(left);
	vector<int> right_sums = subsetsums(right);

	sort(right_sums.begin(), right_sums.end());

	int ans = 0;

	for (auto x : left_sums) {
		ans += upper_bound(right_sums.begin(), right_sums.end(), b - x) -
		       lower_bound(right_sums.begin(), right_sums.end(), a - x);
	}

	cout << ans;











	return 0;
}