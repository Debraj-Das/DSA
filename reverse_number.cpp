#include <iostream>
using namespace std;

int main()
{
    register long long int n, reverse;
    cout << "\nEnter the number :: ";
    cin >> n;
    for (reverse = 0; n; n /= 10)
        reverse = (reverse * 10 + n % 10);
    cout << "\nReverse number is " << reverse << endl;
    return 0;
}