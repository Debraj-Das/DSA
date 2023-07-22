#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        bool nag = false;
        int i = 0;
        for (; s[i] and (s[i] < '0' or s[i] > '9'); i++)
        {
            if (s[i] == '-')
            {
                nag = true;
                i++;
                break;
            }
            if (s[i] == '+')
            {
                i++;
                break;
            }
            if (s[i] != ' ')
                return 0;
        }

        long long ans = 0;
        for (; s[i] >= '0' and s[i] <= '9'; i++)
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX)
                return nag ? INT_MIN : INT_MAX;
        }
        return nag ? -ans : ans;
    }
};

int main()
{
    Solution obj;
    string s = "  -48247 mladjs";
    cout << obj.myAtoi(s) << endl;
    return 0;
}