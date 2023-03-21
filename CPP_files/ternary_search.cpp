#include<bits/stdc++.h>

using namespace std;

double f(double x) {
	double y = - (x * x) + 3.45621278 * x;
	return y;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double left = -100, right = 100;

	while (right - left > 0.00000000001) {

		double mid1 = (2 * left + right) / 3;
		double mid2 = (left + 2 * right) / 3;

		if (f(mid1) < f(mid2)) {
			left = mid1;
		}
		else {
			right = mid2;
		}

	}

	cout << setprecision(15) << fixed;

	cout << left << " " << right << '\n';

	return 0;
}