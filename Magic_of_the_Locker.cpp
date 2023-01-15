/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;

// #define int long long int
// const int mod = 1e9 + 7;

inline int power(int a)
{
     const int mod = 1e9 + 7;
    long long int x  , b ;
    if(a%3==1)
    {
        x = 4 ;
        b = (a-4)/3 ;
    }
    else if(a%3==2)
    {
        x=2 ;
        b = ((a-2)/3);
    }
    else
    {
        x=1 ;
        b = (a/3);
    }
    long long int index = 3 ;
    while (b)
    {
        if (b & 1)
            x *= index, x %= mod;
        index *= index;
        index %= mod;
        b >>= 1;
    }
    return x;
}


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
//	cin >> t;
    while (t--) solve();  // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    int n ;
    cin>>n;
    cout<< power(100) <<endl; 
    
    return ;
}