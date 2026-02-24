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
	int n, m;
	cin>>n>>m;

	vector<vector<int>> gr(n+1), rev(n+1);
	vector<int> ind(n+1, 0);
	for(int i = 0 , x, y ; i < m ; i++){
		cin>>x>>y;
		gr[x].push_back(y);
		rev[y].push_back(x);
		ind[y]++;
	}

	queue<int> pq;
	for(int i = 1 ; i <= n ; i++){
		if(ind[i] == 0){
			pq.push(i);
		}
	}

	vector<int> order;
	while(pq.size()){
		int u = pq.front();
		pq.pop();
		order.push_back(u);
		for(int v: gr[u]){
			ind[v]--;
			if(ind[v] == 0){
				pq.push(v);
			}
		}
	}

	if((int)order.size() != n){
		cout<<"Cycle Present in Graph, so topological ordering not possible";
		return;
	}

	int source , dist;
	cin>>source>>dist;

	vector<int> path(n+1, 0);
	path[source] = 1;

	for(int &u: order){
		/* cout<<"node : "<<u<<" : "; */
		for(int &v: rev[u]){
			/* cout<<v<<sp; */
			path[u] += path[v];
		}
		/* cout<<el; */
	}


	cout<<path[dist];
	/* for(int i = 1; i <= n ; i++){ */
	/* 	cout<<i << " : " << path[i]<<el; */
	/* } */

    return;
}
