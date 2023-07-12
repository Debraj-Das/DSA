/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
	cin >> t;
    while (t--) solve();  // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int check(string s,int n)
{
    for(int i = 0 ; i<(n-1);++i)
    {
        if((s[i]=='R'&&s[i+1]=='L'))
        return 0 ;
        else if((s[i]=='L'&&s[i+1]=='R'))
        return (i+1);
    }
    return -1 ;
}

void solve()
{
    int n ;
    string s;
    cin>>n>>s;
    cout<<check(s,n)<<endl;
    
    return ;
}