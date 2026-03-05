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

void func(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}

	int x1, y1;
	func(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a/b);
	return;
}

void solve() {
	int a, b, c;
	cin>>a>>b>>c;

	int g = __gcd(a,b);
	if(c%g != 0){
		cout<<"No answer possible";
		return;
	}

	int k = c/g;

	int x, y;
	func(a,b,x,y);

	x = k*x;
	y = k*y;

	for(int i = 0 ; i < 20 ; i++){
		cout<<x<<sp<<y<<el;
		// a*x + b*y = c => a*(x+b/g) + b*(y-a/g) = c
		x = x + b/g;
		y = y - a/g;
	}

	cout<<x<<sp<<y;

    return;
}
