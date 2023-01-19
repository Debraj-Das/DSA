/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;
void solve() ;

#define int long long int
const int mod = 1e9 + 7;

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a, x %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return x;
}

inline int mode_multipul(int a , int b)
{
    int x ;
    for(x = 0 ; b ; b>>=1)
    {
        if(b&1) x+=a, x %= mod;
        a <<=1 , a%= mod ;
    }
    return x ;
}


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

void solve()
{
    // cout<<power(2,24524)<<endl;
    cout<<mode_multipul(2904357,3948)<<endl;
    return ;
}

