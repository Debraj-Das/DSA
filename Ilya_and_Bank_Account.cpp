#include <bits/stdc++.h>
using namespace std;

// int firstDigit(int n)
// {
//     // Remove last digit from number
//     // till only one digit is left
//     n = abs(n);
//     while (n >= 10)
//         n /= 10;

//     // return the first digit
//     return n;
// }

// // Find the last digit
// int lastDigit(int n)
// {
//     // return the last digit
//     n = abs(n);
//     return (n % 10);
// }

// int removeFirst(int x)
// {
//     if (x < 10)
//         return 0;
//     return x % 10 + 10 * removeFirst(x / 10);
// }

// void correct_solution()
// {
//     int n;
//     cin >> n;
//     if (n < 0)
//         n = (-1) * min(removeFirst(abs(n)), abs(n) / 10);
//     cout << n << '\n';
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     if (n < 0)
//     {
//         if (lastDigit(n) >= firstDigit(n))
//             n /= 10;
//         else
//             n = (-1) * removeFirst(abs(n));
//     }
//     cout << n << '\n';
//     return;
// }

void solve()
{
    int n;
    cin >> n;
    if (n < 0)
        if (abs(n) % 10 >= ((abs(n) % 100) / 10))
            n /= 10;
        else
        {
            int temp = abs(n) % 10;

            n /= 100;
            n = (n * 10) - temp;
        }
    cout << n << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}