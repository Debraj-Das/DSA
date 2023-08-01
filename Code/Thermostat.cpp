/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define pii pair<int, int>
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back

#define si set<int>

inline int exp(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin>>t ;
    while(t--) solve();

    return 0;
}

inline void solve()
{
    int l , r , x ;
    cin>>l>>r>>x ;
    int a , b ;
    cin>>a>>b ;

    int ans = -1 ;

    if(a==b) ans = 0 ;
    else if(abs(a-b) >= x) ans = 1 ;
    else if((r-b <x and b-l <x) or (r-a <x and a-l <x)) ans = -1 ;
    else if(r-b >= x and b-l >= x) ans = 2 ;
    else
    {
        if(r-b >= x) b = r ;
        else b = l ;
        if(abs(a-b) >= x) ans = 2 ;
        else ans = 3 ;
    }

    cout<<ans<<el ;

    return;
}
