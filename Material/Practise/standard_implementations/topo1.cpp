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


bool dfs(int u, vector<vector<int>> &gr, vector<int> &vis, vector<int> &order){
	vis[u] = 1;
	for(int v: gr[u]){
		if(vis[v] == 1) return false;
		if(vis[v] == 2) continue;
		if(!dfs(v, gr, vis, order)){
			return false;
		}
	}

	order.push_back(u);
	vis[u] = 2;
	return true;
}

void solve() {
	int n, m;
	cin>>n>>m;

	vector<vector<int>> gr(n+1);
	for(int i = 0 , u, v; i < m ; i++){
		cin>>u>>v;
		gr[u].push_back(v);
	}

	vector<int> vis(n+1, 0);
	vector<int> order;

	for(int i = 1; i <= n ; i++){
		if(vis[i]) continue;
		if(!dfs(i, gr, vis, order)){
			cout<<"Cycle Present in Graph, so topological ordering not possible";
			return;
		}
	}

	// we get the order in reverse order after dfs
	reverse(order.begin(), order.end());

	for(int &u: order){
		cout<<u<<' ';
	}

    return;
}
