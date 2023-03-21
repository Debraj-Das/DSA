//{ Driver Code Starts
#include <iostream>
#include <algorithm>
#include <cstdio>
// #include<Windows.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /*You are requried to complete this method */
    int max_Books(int a[], int n, int k)
    {
        // Your code here
        int max_sum , i  , sum ;
        for (i = 0, sum = 0, max_sum = 0 ; i < n; ++i)
            if (k < a[i])
            {
                if (max_sum < sum)
                    max_sum = sum;
                sum = 0;
            }
            else
                sum += a[i];
        if (max_sum < sum)
                    max_sum = sum;
        return max_sum;
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
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends