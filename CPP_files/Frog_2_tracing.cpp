#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5;
int n, k;
int h[N];
int dp[N];

void go(int i) {
	cout << i + 1 << " ";
	for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
		if (dp[i] == dp[i - kk] + abs(h[i] - h[i - kk])) {
			go(i - kk);
			return;
		}
	}
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}


	dp[0] = 0;
	dp[1] = dp[0] + abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = INT_MAX;
		for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
			dp[i] = min(dp[i], dp[i - kk] + abs(h[i] - h[i - kk]));
		}
	}

	cout << dp[n - 1];

	// for (int i = 0; i < n; i++) {
	// 	cout << dp[i] << " ";
	// }

	//trace back
	// go(n - 1);

	return 0;
}