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
    int n ;
    cin >> n ;
    if(n>45)
    {
        cout << -1 << el ;
        return ;
    }
    string s = "" ;
    for(int i = 9 ; n ; i--)
    {
        if(n<i)
        {
            s += to_string(n) ;
            n = 0 ;
        }
        else
        {
            s += to_string(i) ;
            n -= i ;
        }
    }
    reverse(s.begin(), s.end()) ;
    cout << s << el ;
    
    return ;
}