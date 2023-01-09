
//! I did not solve it Data - 8/01/2023

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        // Your code here
        int first = 0, last = N - 1, mid = N;
        for (int i = 1, j = N - 2; (i < last) || (j > first);)
        {

            if ((i < last) and arr[i] > arr[first] and arr[i] < arr[last])
            {
                mid = arr[i];
                break;
            }

            if ((j > first) and arr[j] > arr[first] and arr[j] < arr[last])
            {
                mid = arr[i];
                break;
            }

            if ((i < last) and arr[i] < arr[first])
                first = i;

            if ((j > first) and arr[j] > arr[last])
                last = j;

            if ((i < last))
                ++i;
            if ((j > first))
                --j;
        }
        cout << arr[first] << ' ' << arr[mid] << ' ' << arr[last] << endl;
        if ((arr[mid] < arr[last]) and (arr[mid] > arr[first]))
            return {arr[first], arr[mid], arr[last]};
        else
            return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
