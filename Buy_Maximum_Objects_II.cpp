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
//	cin >> t;
    while (t--) solve();

    return 0;
}

void solve()
{
    int N , Q ; cin>>N>>Q;
    int arr[N] ; f(i , 0 , N) cin>>arr[i];
    sort(arr , arr+N);
    f(i , 1 , N) arr[i] += arr[i-1];
    int x  , ans;
    while(Q--)
    {
        cin>>x ;
        ans = distance(arr ,upper_bound(arr , arr+N , x));
        cout<<ans<<el;
    }
    
    return ;
}