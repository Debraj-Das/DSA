#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int h[n];

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int dp[n];

	dp[0] = 0;
	dp[1] = dp[0] + abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2]
		            + abs(h[i - 2] - h[i]));
	}

	cout << dp[n - 1];




	return 0;
}