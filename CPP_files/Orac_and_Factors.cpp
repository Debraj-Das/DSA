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

int small_divisor(int n)
{
    if(n % 2 == 0) return 2 ;
    for(int i = 3; i * i <= n; i++)
        if(n % i == 0) return i ;
    return n ;
}

void solve()
{
    int n , k ;
    cin >> n >> k ;
    cout << n + small_divisor(n) + 2 * (k - 1) << el ;
    
    return ;
}