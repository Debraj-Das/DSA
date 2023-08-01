#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x = -x;
        }
        long long ans = 0;
        while (x)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (neg)
            ans = -ans;
        if (ans > INT_MAX || ans < INT_MIN)
            return 0;
        return ans;
    }
};

int main()
{
    Solution sol;
    int x = -123;
    cout << sol.reverse(x) << endl;
    return 0;
}