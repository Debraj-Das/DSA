#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5;

int a[N][3], dp[N][3];

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int jj = 0; jj < 3; jj++) {
				if (j != jj) {
					dp[i][j] = max(dp[i][j], dp[i - 1][jj] + a[i][j]);
				}
			}
		}
	}

	cout << *max_element(dp[n - 1], dp[n - 1] + 3);









	return 0;
}