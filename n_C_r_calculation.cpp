#include <iostream>
using namespace std;

int main()
{
    register long long int  n, vaule;
    cout << "Enter the (n , r) :: ";
    cin >> n >> vaule;
    const long long int r = vaule;
    vaule = 1;
    for (register long long int i = 1; i <= r; ++i, --n)
    {
        vaule = (vaule*n)/i ;
    }
    cout << "Vaule = " << vaule << endl;
    return 0;
}