//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        if((n == 0) || n == (-1)) return (-1);
        int mid = (n/2);
        int index ;
        
        if(arr[mid]== k)
        return mid ;
        else if(arr[mid] > k)
        return binarysearch(arr , mid , k);
        else 
        {
            index = binarysearch(&arr[mid+1] , n-mid-1, k );
            if(index != (-1))
            index+=(mid+1);
             return index;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends