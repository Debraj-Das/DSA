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
    int n ; cin>>n;
    int arr[n] ; f(i,0,n) cin>>arr[i];
    string s ; int f , l ; f = l = arr[0];
    bool life = true ;
    f(i,0,n)
    {
    	if(life)
    	{
    		if(arr[i]>=l)
    		{
    			s.push_back('1');
    			l = arr[i];
    		}
    		else if(arr[i] <= f)
    		{
    			s.push_back('1');
    			l = arr[i];
    			life = false ;
    		}
    		else s.push_back('0');
    	}
    	else 
    	{
    		if(arr[i] >= l and arr[i] <= f)
    		{
    			s.push_back('1');
    			l = arr[i];
    		}
    		else 
    		s.push_back('0');
    	}
    }
    cout<<s<<el;
    
    return ;
}