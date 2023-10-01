//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    const int mod = 1e9 + 7;

  public:
    int CountString(int X, int Y)
    {
        Y++;
        if (Y < X)
        {
            return 0;
        }

        long long num = 1;
        for (int i = 2; i < Y + 1; i++)
        {
            num = (num * i) % mod;
        }
        long long dom = 1;
        for (int i = 2; i < X + 1; i++)
        {
            dom = (dom * i) % mod;
        }
        for (int i = 2; i < (Y - X + 1); i++)
        {
            dom = (dom * i) % mod;
        }

        long long abc = expo(dom);

        // cerr << num << ' ' << dom << ' ' << abc << '\n';

        num = (num * abc) % mod;

        return num;
    }

    int expo(long long a)
    {
        long long res = 1, b = mod - 2;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int X, Y;
        cin >> X >> Y;
        Solution obj;
        int res = obj.CountString(X, Y);
        cout << res << endl;
    }
}

// } Driver Code Ends