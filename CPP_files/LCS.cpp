#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3000;

string s, t, res;
int n, m, memo[N][N];

int give_lcs(int i, int j) {
	if (i == n || j == m) return 0;

	int &ans = memo[i][j];

	if (ans != -1) return ans;

	if (s[i] == t[j]) ans = give_lcs(i + 1, j + 1) + 1;
	else ans = max(give_lcs(i + 1, j), give_lcs(i, j + 1));

	return ans;
}

void trace_back(int i, int j) {
	if (i == n || j == m) return;

	if (s[i] == t[j]) res += s[i], trace_back(i + 1, j + 1);
	else {
		if (give_lcs(i + 1, j) == give_lcs(i, j)) trace_back(i + 1, j);
		else trace_back(i, j + 1);
	}
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s >> t;
	n = s.size();
	m = t.size();

	memset(memo, -1, sizeof(memo));

	int l = give_lcs(0, 0);

	trace_back(0, 0);

	cout << res;

	return 0;
}