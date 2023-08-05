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
   int n ;
   cin>>n ;
   int arr[n+2] ; 
   f(i , 1 , n+1) cin>>arr[i];
   arr[0] = INT_MIN ;
   arr[n+1] = INT_MIN;

   int nex[n] , pre[n];

   stack<int> st ;
   st.push(n+1) ;

   for(int i = n , j; i > 0 ; i--)
   {
        j = st.top();
        while(arr[j] > arr[i])
        {
            st.pop();
            j = st.top();
        }
        nex[i-1] = j ;
        st.push(i) ;
   }

   while(!st.empty()) st.pop();

   st.push(0) ;

   for(int i = 1 , j ; i <= n ; i++)
   {
        j = st.top();
        while(arr[j] > arr[i])
        {
            st.pop();
            j = st.top();
        }
        pre[i-1] = j ;
        st.push(i) ;
   }

   int ans = 0 ; 
   for(int i = 0 ; i<n ; i++)
   ans += arr[i+1]*(nex[i] -i -1)*(i + 1 - pre[i]) ;

   cout<<ans<<el;

    return;
}
