#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN and divisor == -1)
            return INT_MAX;

        return dividend / divisor;
    }
};

int main()
{
    Solution obj;
    cout << obj.divide(7, -3) << endl;
    return 0;
}