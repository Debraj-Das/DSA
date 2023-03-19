#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n;

	m = sqrt(n) + 1;

	int a[n], b[m];
	memset(b, 0, sizeof(b));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i / m] += a[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r, ans = 0;
		cin >> l >> r;

		for (int i = l; i <= r;) {
			if (i % m == 0 && i + m - 1 <= r) {
				// lies completely inside the [l...r]
				ans += b[i / m];
				i += m;
			}
			else {
				ans += a[i];
				i++;
			}

		}

		cout << ans << '\n';

	}












	return 0;
}