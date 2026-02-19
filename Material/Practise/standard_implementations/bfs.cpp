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

void solve() {
	int n, m;
	cin>>n>>m;

	vector<vector<int>> gr(n);
	for(int i = 0, u, v; i < m ; i++){
		cin>>u>>v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	constexpr int inf = 1e9+7;
	vector<int> dist(n, inf);
	
	int source; // source node
	cin>>source;

	dist[source] = 0;
	queue<int> qu;
	qu.push(source);

	while(qu.size()){
		int u = qu.front();
		qu.pop();
		for(int v: gr[u]){
			if(dist[v] > dist[u]+1){
				dist[v]  = dist[u]+1;
				qu.push(v);
			}
		}
	}

	// dist vector store that distance between source to any node,
	// if dist of node is inf that we can not reach from source


    return;
}
