/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

constexpr int bz = 450;

void solve() {
	int n, q;
	cin>>n>>q;

	vector<int> ar(n);
	for(int &e: ar) cin>>e;

	vector<ll> br((n-1+bz)/bz, 0);
	for(int i = 0 ; i < n ; i++){
		br[i/bz] += ar[i];
	}

	int l, r;
	while(q--){
		cin>>l>>r;
		int cl = l/bz, cr = r/bz;
		ll ans = 0;

		if(cl == cr){
			for(int i = l; i <= r; i++){
				ans += ar[i];
			}
		}else {
			for(int i = l, ed = (cl+1)*bz; i < ed ; i++){
				ans += ar[i];
			}

			for(int i = cl+1; i < cr ; i++){
				ans += br[i];
			}

			for(int i = cr*bz ; i <= r; i++){
				ans += ar[i];
			}
		}

		cout<<ans<<el;
	}

    return;
}
