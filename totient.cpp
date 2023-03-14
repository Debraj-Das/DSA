#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e5;

void calculate_totient() {
	vector<bool> pr(N, true);
	vector<int> tot(N);

	for (int i = 2; i < N; i++) {
		for (int j = i * i; j < N; j += i) {
			pr[j] = false;
		}
	}

	iota(tot.begin(), tot.end(), 0);

	for (int i = 2; i < N; i++) {
		if (pr[i] == true) {

			// multiples of prime
			for (int j = i; j < N; j += i) {
				// j is divisible by i
				// i is prime
				tot[j] /= i;
				tot[j] *= (i - 1);
			}
		}
	}

	// for (int i = 1; i <= 10; i++) {
	// 	cout << i << " " << tot[i] << '\n';
	// }

}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	calculate_totient();

	return 0;
}