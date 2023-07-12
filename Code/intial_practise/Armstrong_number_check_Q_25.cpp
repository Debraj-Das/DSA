#include <iostream>
using namespace std;

int main()
{
    register long long int n, check_number;
    cout << "\nEnter the number :: ";
    cin >> n;
    const long long int store = n;
    register int last_digit;
    for (check_number = 0; n; n /= 10)
    {
        last_digit = (n % 10);
        check_number += (last_digit * last_digit * last_digit);
    }
    if (store == check_number)
        cout << store << " is a Armstrong number" << endl;
    else
        cout << store << " is not a Armstrong number" << endl;
    return 0;
}