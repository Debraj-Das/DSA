//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int i, j, k;
        long long int maxele = arr1[0];
        for (i = 0; i < n; ++i)
            if (maxele < arr1[i])
                maxele = arr1[i];
        for (i = 0; i < m; ++i)
            if (maxele < arr2[i])
                maxele = arr2[i];
        maxele+=1 ;
        for (i = 0, j = 0, k = 0; i < n && j < m; ++k)
        {
            if (arr1[i] % maxele <= arr2[j] % maxele)
            {
                if (k < n)
                    arr1[k] = arr1[k] + (arr1[i] % maxele) * maxele;
                else
                    arr2[k - n] = arr2[k - n] + (arr1[i] % maxele) * maxele;
                i++;
            }
            else
            {
                if (k < n)
                    arr1[k] = arr1[k] + (arr2[j] % maxele) * maxele;
                else
                    arr2[k - n] = arr2[k - n] + (arr2[j] % maxele) * maxele;
                j++;
            }
        }
        while (i < n)
        {
            if (k < n)
                arr1[k] = arr1[k] + (arr1[i] % maxele) * maxele;
            else
                arr2[k - n] = arr2[k - n] + (arr1[i] % maxele) * maxele;
            i++;
            ++k;
        }
        while (j < m)
        {
            if (k < n)
                arr1[k] = arr1[k] + (arr2[j] % maxele) * maxele;
            else
                arr2[k - n] = arr2[k - n] + (arr2[j] % maxele) * maxele;
            j++;
            k++;
        }

        // Obtaining actual values
        for (i = 0; i < n; ++i)
            arr1[i] = arr1[i] / maxele;
        for (j = 0; j < m; ++j)
            arr2[j] = arr2[j] / maxele;
        return;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends