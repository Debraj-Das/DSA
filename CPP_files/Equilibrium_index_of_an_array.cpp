//{ Driver Code Starts
#include <iostream>
using namespace std;

int findEquilibrium(int[], int);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << findEquilibrium(a, n) << endl;
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends

/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
    // Your code here
    int i, pos_sum, pre_sum;
    for (i = 0, pos_sum = 0; i < n; ++i)
        pos_sum += A[i];
    for (i = 0, pre_sum = 0; i < n; ++i)
    {
        pos_sum -= A[i];
        if (pre_sum == pos_sum)
            return i;
        else
            pre_sum += A[i];
    }
    return -1;
}