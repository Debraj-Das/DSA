//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

int transitionPoint(int arr[], int n)
{
    // code here
    if (arr[0] == 1)
     return 0;
    else if (arr[n - 1] == 0)
        return (-1);
    else
    {
        for (int first = 0, end = n - 1, mid = (first + end) / 2; first <= end; mid = (first + end) / 2)
        {
            if ((arr[mid] == 1) && (arr[mid - 1] == 1))
                end = mid - 1;
            else if ((arr[mid] == 0) && (arr[mid + 1] == 0))
                first = mid + 1;
            else
            {
                if (arr[mid])
                    return mid;
                else
                    return mid + 1;
            }
        }
    }
    return 0;
}