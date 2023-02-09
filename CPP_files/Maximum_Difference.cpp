// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main()
// {

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     vector<int> arr = {20, 30, 40, 40, 40, 50, 100, 1100};
//     int n = arr.size();
//     // Search in a sorted array
//     int key;
//     cin >> key;

//     cout << *(lower_bound(arr.begin(), arr.end(), key)-1) << endl;

//     // cout<< upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n,key) <<endl;

//     return 0;
// }

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method */
    int Different(int arr[], int n, int index)
    {
        int minl, minr, i;
        for (i = index - 1, minl = 0; i >= 0; i--)
            if (arr[i] < arr[index])
            {
                minl = arr[i];
                break;
            }

        for (i = index + 1, minr = 0; i < n; i++)
            if (arr[i] < arr[index])
            {
                minr = arr[i];
                break;
            }
        return abs(minr - minl);
    }
    int findMaxDiff(int A[], int n)
    {
        // Your code here
        int MaxDiff = 0;
        for (int i = 0, diff; i < n; ++i)
        {
            diff = Different(A, n, i);
            MaxDiff = max(MaxDiff, diff);
        }
        return MaxDiff;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.findMaxDiff(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends