/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';

inline void solve();

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC = 1;
    /* cin >> TC; */
    for (int i = 0; i < TC; i++) {
        /* cout<<"case "<<(i+1)<<": "; */
        solve();
        cout << '\n';
    }

    return 0;
}

vector<vector<int>> manacher(const string &s) {
    if (s.empty())
        return {{}, {}};
    string t = "@";
    for (auto c : s) {
        t += string("#") + c;
    }
    t += "#$";

    const int n = t.size();
    vector<int> p(n, 0);
    for (int i = 1, l = 0, r = 0; i < n-1; i++) {
        if (i < r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }
        while (t[i - p[i] - 1] == t[i + p[i] + 1]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    const int N = s.size();
    vector<vector<int>> ans(2, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        // in index calculation, 2 is extra due to "@#" at the starting point
        ans[0][i] = p[2 * i + 2]; // odd
        ans[1][i] = p[2 * i + 3]; // even
    }

    return ans;
}

void solve() {
	string s;
	cin>>s;

	vector<vector<int>> ans = manacher(s);

	int slv = 1, j = 0;

	for(size_t i = 0 ; i < s.size() ; i++){
		if(ans[0][i] > slv){
			slv = ans[0][i];
			j = i - (slv/2);
		}

		if(ans[1][i] > slv){
			slv = ans[1][i];
			j = i - (slv/2) + 1;
		}
	}
	string b = s.substr(j, slv);

	cout<<b;

    return;
}
