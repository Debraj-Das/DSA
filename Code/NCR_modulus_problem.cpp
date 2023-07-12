//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

#define M  1000000007

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int nCr(int n, int r){
        // code here
    int fac = 1 ;
    for(int i = 1 ; i <= r ; ++i)
    {
        fac = ((((fac)%M)*(n+1-i))/i)%M ;
    }
        return fac ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends