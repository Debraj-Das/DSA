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

vector<pair<int,int>> number(int n)
{
    int a[n];
    f(i , 0 , n) cin>>a[i] ;

    vector<pair<int,int>> v ;
    set<int> s ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(s.find(a[i]) == s.end())
        {
            s.insert(a[i]) ;
            v.push_back({a[i] , i+1}) ;
        }
    }

    return v ;
}

inline void solve()
{
   int n ;
   cin>>n ;
   vector<pair<int,int>> v = number(n) ;

   n = v.size() ;
   int ans = -1 ;
   for(int i = 0 , j ; i < n ;i++)
    {
        if(v[i].ff == 1) ans = max(ans , 2*v[i].ss) ;

         j = i+1 ;
         while(j < n and __gcd(v[i].ff , v[j].ff) != 1) j++ ;
         if(j < n) ans = max(ans , v[i].ss + v[j].ss) ;
    }

    cout<<ans<<el ;

    return;
}
