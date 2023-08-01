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
    // take input here
    int n  ;
    cin>>n;
    string s ;
    cin>>s;
    int arr[n];
    f(i,0,n) cin>>arr[i];

    // find the first 0
    int i = 0 ;
    while(i < n and s[i] == '1') i++ ;

    // swaping the lid of the box
    for(int j = i+1 ; j < n ; j++)
        if(arr[i] > arr[j] and s[j] == '1')
            swap(s[i],s[j]) , i = j ;
        else if(s[j] == '0')
            i = j ;
    
    // calculate the total sum
    int sum = 0 ;
    f(i,0, n) sum += arr[i]*(s[i] == '1') ;
    
    // print the answer
    cout<<sum<<el;

    return;
}
