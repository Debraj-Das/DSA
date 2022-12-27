//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define long long int int;
// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int i = 0, j = 0;
        int sum_a = 0, sum_b = 0;
        int total_sum = 0;

        while ((i < l1) && (j < l2))
        {
            if (A[i] == B[j])
            {
                sum_a += A[i];
                sum_b += B[j];
                if (sum_a > sum_b)
                    total_sum += sum_a;
                else
                    total_sum += sum_b;
                ++i;
                ++j;
                sum_a = 0;
                sum_b = 0;
            }
            else if (A[i] > B[j])
            {
                sum_b += B[j];
                ++j;
            }
            else
            {
                sum_a += A[i];
                ++i;
            }
        }
        while (i < l1)
        {
            sum_a += A[i];
            ++i;
        }
        while (j < l2)
        {
            sum_b += B[j];
            ++j;
        }
        if (sum_a > sum_b)
            total_sum += sum_a;
        else
            total_sum += sum_b;

        return total_sum;
    }
};

//{ Driver Code Starts.

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        // fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        Solution obj;
        int result = obj.max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends