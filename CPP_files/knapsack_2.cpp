#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 101;

int v[N], w[N], W, n, mW[N][100001], dp[N][100001];

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> W;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int val = 0; val < 100001; val++) {
			mW[i][val] = 1e13;
		}
	}

	dp[0][0] = 1;
	mW[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int val = 0; val < 100001; val++) {
			// not taking
			if (dp[i - 1][val]) {
				dp[i][val] = 1;
				mW[i][val] = min(mW[i][val], mW[i - 1][val]);
			}
			// taking item
			if (val - v[i] >= 0 && dp[i - 1][val - v[i]]
			        && mW[i - 1][val - v[i]] + w[i] <= W) {
				dp[i][val] = 1;
				mW[i][val] = min(mW[i][val], mW[i - 1][val - v[i]] + w[i]);
			}
		}
	}

	int ans = 0;
	for (int val = 0; val < 100001; val++) {
		if (dp[n][val]) ans = val;
	}

	cout << ans;




	return 0;
}