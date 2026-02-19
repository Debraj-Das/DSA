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

void dfs(int u, vector<bool> &vis,const vector<vector<int>> &gr){
	vis[u] = true;
	for(int v: gr[u]){
		if(vis[v]) continue; // if previous it visited then no need to visited again
		// code for algo to unvisited node
		dfs(v, vis, gr);
	}

	// after visited all the child of node u
}

void solve() {
	int n, m; // n: number of node and m: number of Edges
	cin>>n>>m;

	vector<vector<int>> gr(n); // Here assumsed that node id: 0, 1, ..., n-1
	for(int i = 0 , x, y ; i < m ; i++){
		cin>>x>>y;
		gr[x].push_back(y);  // (x -> y)
		gr[y].push_back(x); // if bidirections of edges, (y -> x)
	}

	vector<bool> vis(n, false); // use this vector to track the visited node
	dfs(0, vis, gr);

    return;
}
