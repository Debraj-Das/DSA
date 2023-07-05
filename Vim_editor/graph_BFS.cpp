#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define ff first
#define ss second
#define pii pair<int, int>

#define vi vector<int>
#define pb push_back

#define si set<int>

inline int exp(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1)
			x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

inline void solve() ;
void bfs(int u , vi gr[] , bool visit[]);

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
#endif

    clock_t z = clock();

    int t = 1;
	// cin >> t;
    while (t--) 
	solve();

    cerr << "\nRun Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC)<<el;

    return 0;
}

inline void solve()
{
	// intiallised the graph 
	int v ;
	cin>> v ;
	vi gr[v];
	int e , x , y ;
	cin>>e ;
	f(i , 0 , e)
	{
		cin>>x>>y ;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	// algorithm for bfs
	bool visit[v] = {false};
	f(i , 0 , v)
	{
		if(!visit[i]) bfs(i , gr , visit);
	}
    return ;
}

void bfs(int u , vi gr[] , bool visit[])
{
	cout<<u<<sp ;
	visit[u] = true ;
	for(int v : gr[u])
	{
		if(!visit[v]) bfs(v , gr , visit);
	}
	return ;
}


