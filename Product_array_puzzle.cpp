//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        // code here
        vector<long long int> P(n);
        if (n == 1)
            P[0] = 1;
        int flag = 0;
        long long int mul = 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i])
                mul *= nums[i];
            else
                ++flag;
        }
        if (flag > 1)
        {
            for (int i = 0; i < n; i++)
                P[i] = 0;
        }
        else if (flag == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i])
                    P[i] = 0;
                else
                    P[i] = mul;
            }
        }
        else
        for (int i = 0; i < n; i++)
            P[i] = (mul / nums[i]);

        return P;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends