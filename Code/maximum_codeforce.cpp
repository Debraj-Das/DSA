#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, x, i;
    for (i = 0, x = 0; i < n; ++i)
    {
        cin >> b;
        a = b + x;
        cout << a << ' ';
        if (a > x)
            x = a;
    }

    return 0;
}