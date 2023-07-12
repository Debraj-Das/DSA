//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long minNumber(long long arr[],long long N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    cout << minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends

bool is_nonPrime(ll n)
{
    ll squar_root = sqrt(n);
    for(ll i = 2 ; i <= squar_root ; ++i)
    if(n%i==0)
    return true ;
    return  false ;
}


long long minNumber(long long arr[],long long N)
{
    ll sum = 0 , small_num  ;
    for(ll i = 0 ; i <N ;++i)
    sum += arr[i];
    for(small_num = 0 ; is_nonPrime(sum+small_num);++small_num);
    return small_num ;
}
