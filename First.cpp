/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define el '\n'
#define f(i,a,b) for(int i = a; i < b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t = 1;
	cin >> t;
    while (t--) solve();

    return 0;
}


void solve()
{
	int n , k , q ; cin>>n>>k>>q ;
	int tem[n] ; f(i,0,n) cin>>tem[i];
	int ans = 0 , l = 0 ;
	f(i,0,n)
	{
		if(tem[i] <= q) l++;
		else
		{
			if(l>=k)
			ans += ((l-k+1)*(l-k+2)/2);
			l = 0 ;
		}
	}
	if(l>=k) ans+= (l-k+1)*(l-k+2)/2;
	cout<<ans<<el;
	
    
    return ;
}