#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5;

int h[N], memo[N];

int dp(int n) {
	if (n == 0) return 0;

	int &ans = memo[n];

	if (ans != -1) return ans;

	ans = dp(n - 1) + abs(h[n - 1] - h[n]);

	if (n - 2 >= 0) ans = min(ans, dp(n - 2) + abs(h[n - 2] - h[n]));

	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	memset(memo, -1, sizeof(memo));

	cout << dp(n - 1);

	return 0;
}