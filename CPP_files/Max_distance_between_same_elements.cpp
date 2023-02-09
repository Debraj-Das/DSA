//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        // Code here
        unordered_map<int, int> unq;
        int max_Distance, i;
        for (max_Distance = 0, i = 0; i < n; ++i)
        {
            if (unq.find(arr[i]) != unq.end())
                max_Distance = max(max_Distance, i - unq[arr[i]]);
            else
                unq[arr[i]] = i;
        }
        return max_Distance;
    }
};

//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.maxDistance(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends