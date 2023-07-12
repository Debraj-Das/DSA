//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string answer(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        
        cout<< answer(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
bool equal_diff(int a[], int n)
{
    int i , diff = a[0] - a[1] ;
    if(diff == 0) 
        return false ;
    for(i = 1 ; i< n/2 ; ++i)
    if(diff != (a[i]- a[i+1]))
    return false ;
    for(n-=1; i< n ; ++i)
    if(diff != (a[i+1]- a[i]))
    return false ;

    return true ;
}

string answer(int a[], int n)
{
    if((n%2)&&(a[n/2]==1)&&equal_diff(a,n))
    return "Yes";
    else
    return "No";
}
