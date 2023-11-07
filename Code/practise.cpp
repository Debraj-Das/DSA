#include <bits/stdc++.h>

using namespace std;

const char el = '\n';
const char sp = ' ';

void solve();

int32_t main()
{
	int n;
	cin>>n;

	cout<<(n*n)<<el;

	return 0 ;

}

void solve()
{
	int n ;
	cin>>n;

	int ar[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>ar[i];
	}

	sort(ar , ar+n);
	
	for(int i =0 ; i< n ; i++)
		cout<<ar[i]<<sp;
	cout<<el;
}
