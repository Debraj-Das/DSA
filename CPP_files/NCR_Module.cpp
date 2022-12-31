//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(int n){
        // code here
        long long int a = 1 , b = 1 , store ;
        for(int i= 3 ; i <= n ;++i)
        {
            store = (a+b)%M ;
            a = b ;
            b = store ;
        }
        return b ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends