#include <bits/stdc++.h>
using namespace std;
int small_diversor(int diff)
{
    if(diff%2 == 0)
    return 2 ;
    else
    {
        int small_div = diff, n = sqrt(diff);
        for (int i = 3; i <= n; i+=2)
            if (diff % i == 0)
            {
                small_div = i;
                break;
            }
        return small_div;
    }
}

int main()
{
    int T, x, y, diff;
    cin >> T;
    while (T--)
    {
        //* take input and find different of x and y;
        cin >> x >> y;
        if (x > y)
            diff = x - y;
        else
            diff = y - x;
        //* check every case of inputsP
        //# if different is 1 then k vaule is infinite so print (-1)
        if (diff == 1)
            cout << (-1) << endl;
        //# if number is gcd not equal then k vaule is zero
        else if (gcd(x, y) != 1)
            cout << 0 << endl;
        //# this case first we find smallest diversor of diff and try to find k vaule by dividing
        else
        {
            diff = small_diversor(diff);
            diff = (x / diff + 1) * diff - x;
            cout << diff << endl;
        }
    }
    return 0;
}