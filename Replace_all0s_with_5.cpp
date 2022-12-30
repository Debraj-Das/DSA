#include <iostream>
using namespace std;

int convertFive(int n)
{
    for (int store = n, dec = 1; store; store /= 10, dec *= 10)
        if (store % 10 == 0)
            n += (5 * dec);
    return n;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}