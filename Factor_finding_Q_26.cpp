#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    register long long int number;
    cout << "Enter the number :: ";
    cin >> number;
    const int sn = sqrt(number);
    cout << "The factor are :: " << endl;
    for (register int i = 1, count = 1; i <= sn; ++i)
    {
        if ((number % i) == 0)
        {
            cout << count << ") " << i << " , " << (number / i) << endl;
            ++count ;
        }
    }
    return 0;
}