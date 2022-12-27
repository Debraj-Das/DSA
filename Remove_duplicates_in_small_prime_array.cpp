/*
     অভিজ্ঞতা একটি কঠিন শিক্ষক,
     সে প্রথমে তোমার পরীক্ষা নেয় এবং
     পরে তার পাঠ দেয়।
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        //* code here is my code time - O(n) with space - O(n)
        // set<int> cal = {arr[0]};
        // vector<int> ret = {arr[0]};
        // for (int i = 1; i < n; ++i)
        // {
        //     if(cal.find(arr[i]) == cal.end())
        //     {
        //         ret.push_back(arr[i]);
        //         cal.insert(arr[i]);
        //     }
        // }
        // return ret;
        //* code here is GFG standerd solution time - O(n) with space - O(1)long long int prod = vect[0];
        long long int prod = arr[0];
        int res_ind = 1;
        for (int i = 1; i < n; i++)
        {
            if (prod % arr[i] != 0)
            {
                arr[res_ind++] = arr[i];
                prod *= arr[i];
            }
        }
        arr.erase(arr.begin() + res_ind, arr.end());
        return arr;
    }
};

//{ Driver Code Starts.
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
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends