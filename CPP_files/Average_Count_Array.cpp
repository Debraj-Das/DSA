//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countArray(int a[], int n, int x)
    {
        vector<int> b(n);
        for (int i = 0, avg, j, count; i < n; ++i)
        {
            avg = (a[i] + x) / 2;
            for (j = 0, count = 0; j < n; ++j)
                if (a[j] == avg)
                    ++count;
            b[i] = count;
        }
        return b;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;
        int a[n + 1];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b;
        Solution obj;
        b = obj.countArray(a, n, x);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    }
}

// } Driver Code Ends