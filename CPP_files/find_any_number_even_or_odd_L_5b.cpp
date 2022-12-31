#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "\nEnter a number for check even or odd :: ";
    cin >> number;
    cout << endl;
    if (number % 2)
    {
        cout << number << " is odd number" << endl;
    }
    else
    {
        cout << number << " is even number" << endl;
    }

    return 0;
}