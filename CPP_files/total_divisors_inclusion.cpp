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

	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	int m = primes.size();

	int ans = 0;

	for (int i = 1; i < (1 << m); i++) {

		int lcm = 1;
		for (int j = 0; j < m; j++) {
			// if jth bit of ith element is set then include it
			if ((i >> j) & 1) {
				// cout << primes[j] << " ";
				lcm *= primes[j];
			}
		}
		// cout << '\n';

		if (__builtin_popcount(i) % 2 == 0) {
			ans -= (n / lcm);
		}
		else {
			ans += (n / lcm);
		}
	}


	cout << ans;

	return 0;
}