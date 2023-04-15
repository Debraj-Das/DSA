#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int memo[N];

int dp(int cur) {
	int &ans = memo[cur];
	if (ans != -1) return ans;
	ans = 0;
	for (auto x : gr[cur]) {
		ans = max(ans, dp(x) + 1);
	}
	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
	}

	memset(memo, -1, sizeof(memo));

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp(i));
	}

	cout << ans;

	return 0;
}