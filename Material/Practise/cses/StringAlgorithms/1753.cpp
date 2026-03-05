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

void solve() {
	string s;
	cin>>s;

	string t;
	cin>>t;

	s = t + "#" + s;
	const int n = s.size();
	vector<int> lps(n+1);
	lps[0] = -1;
	for(int i = 0, j = -1; i < n;lps[++i] = ++j){
		while(j != -1 and s.at(j) != s.at(i)) j = lps[j];	
	}

	int count = 0;
	for(int i = 0 ; i <= n ; i++){
		count += (lps[i] == t.size());
	}

	cout<<count;

    return;
}
