#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int ans;
	cin >> ans;
	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a = query(1, 2);
	int b = query(2, 3);
	int c = query(3, 4);
	int d = query(4, 5);


	vector<int> v = {4 , 8, 15, 16, 23, 42};

	do {
		if (v[0]*v[1] == a
		        && v[1]*v[2] == b
		        && v[2]*v[3] == c
		        && v[3]*v[4] == d) {
			cout << "! ";
			for (auto x : v) cout << x << " ";
			cout << endl;
		}
	}
	while (next_permutation(v.begin(), v.end()));











	return 0;
}