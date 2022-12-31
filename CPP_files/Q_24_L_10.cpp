#include <iostream>

using namespace std;

int main()
{
    long long int n, pow, tem, reverse;
    cout << "\nEnter the number :: ";
    cin >> n;
    for (tem = (n / 10), pow = 1; tem; tem /= 10, pow *= 10)  ;
        
    for (tem = n, reverse = 0; tem; pow /= 10, tem /= 10)
    {
        reverse += ((tem % 10) * pow);
    }
    cout << "\nReverse number of " << n << " is " << reverse << endl;
    return 0;
}