//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int count_pairs(vector<char> &arr, string &s, int n, int m)
    {
        // Complete the function
        int alph[52];
        for(int i =0;i<52;++i)
        alph[i] = 0;
        for(int i =0;i<m;++i)
        {
            if((s[i]>=65)&&(s[i]<=90))
            alph[(s[i]-65)]= 1;
            else if((s[i]>=97)&&(s[i]<=122))
            alph[(s[i]-71)]= 1;
        }

        int count = 0 , x , y ;
        for (int i = 0; i < n; i += 2)
        {
            if((arr[i]>=65)&&(arr[i]<=90))
            x = arr[i]-65 ;
            else if((arr[i]>=97)&&(arr[i]<=122))
            x = arr[i] - 71 ;

            if((arr[i+1]>=65)&&(arr[i+1]<=90))
            y = arr[i+1]-65 ;
            else if((arr[i+1]>=97)&&(arr[i+1]<=122))
            y = arr[i+1] - 71 ;

            if(alph[x]&&alph[y])
            count++ ;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<char> arr;

        for (int i = 0; i < 2 * n; i += 2)
        {
            char x, y;
            cin >> x >> y;
            arr.push_back(x);
            arr.push_back(y);
        }
        string s;
        cin >> s;
        Solution ob;
        cout << ob.count_pairs(arr, s, 2 * n, m) << endl;
    }

    return 0;
}
// } Driver Code Ends