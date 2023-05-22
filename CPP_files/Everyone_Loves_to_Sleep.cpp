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
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
#endif

    int t = 1;
	cin >> t;
    while (t--) solve();

    return 0;
}

void solve()
{
    int n , a , b , c , d , ans = 24*60 ;
    cin>> n >> a >>b ;
    a = a*60 + b ;
    f(i,0,n)
    {
        cin>> c >> d ;
        b = c*60 + d ;
        if(b < a) b += 24*60 ;
        ans = min(ans , b-a) ;
    }
    cout<<(ans/60)<<' '<<(ans%60)<<el;
    
    return ;
}