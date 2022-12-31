//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*The function returns an integer
which denotes the max value
of abs(i â€“ j) * min(arr[i], arr[j])
in the array.
*/

/*You are required to complete this method*/
class Solution
{
public:
    int max_val(int arr[], int n)
    {
        // Your code here
        int max, small_index;
        max = INT_MIN;
        for (int i = 0, j = n - 1, val; i < j; (small_index == i) ? ++i : --j)
        {
            if (arr[i] > arr[j])
                small_index = j;
            else
                small_index = i;
            val = (j - i) * arr[small_index];
            if (val > max)
                max = val;
        }
        return max;
    }
};

//{ Driver Code Starts.

int main()
{
    
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
    // your code goes here
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
        cout << ob.max_val(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends