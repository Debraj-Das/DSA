#include <iostream>

using namespace std;

int main()
{
    cout << "\n\n Check overflow/underflow during various arithmetical operation :\n";
    cout << " Range of int is [-2147483648, 2147483647]" << endl;
    cout << "---------------------------------------------------------------------\n";
    
    int n1 = 2147483647; //* maximum range of integer
    cout << " Overflow the integer range and set in minimum range : " << n1 + 1 << endl;
    cout << " Increasing from its minimum range : " << n1 + 2 << endl;
    cout << " Product is :" << (n1 * n1) << endl;

    int n2 = -2147483648; //* minimum range of integer
    cout << " Underflow the range and set in maximum range : " << n2 - 1 << endl;
    cout << " Decreasing from its maximum range : " << n2 - 2 << endl;
    cout << " Product is : " << (n2 * n2) << endl;
    cout << endl;

    return 0;
}
