#include <bits/stdc++.h>
using namespace std;

#define int long long int

int fibonacci(int n)
{
    cout << "hello" << endl;
    if ((n == 1) || (n == 2))
        return 1;
    else if (n % 2)
    {
        int first = fibonacci((n + 1) / 2);
        int second = fibonacci((n - 1) / 2);
        return (first * first + second * second);
    }
    else
    {
        int first = fibonacci(n / 2);
        return (fibonacci(n / 2 - 1) * 2 * first + first * first);
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}