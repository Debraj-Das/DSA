#include <iostream>
using namespace std;

int power(int c, int a)
{
    int pow = 1;
    for (int i = 0; i < a; ++i)
    {
        pow *= c;
    }
    return pow;
}

int main()
{
    long long int a, b, tem;
    int p;
    cout << "Enter the number :: ";
    cin >> a;
    for (tem = a, p = 0; tem > 0; ++p)
        tem /= 10;

    for (b = 0, tem = a; tem > 0; tem /= 10)
    {
        b += power((tem % 10), p);
    }
    if (b == a)
        cout << "[" << a << "] is an Armstrong number.\n";
    else
        cout << "[" << a << "] is Not an Armstrong number.\n";

    return 0;
}