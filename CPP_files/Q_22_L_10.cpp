#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    double value;
    cout << "Enter no of order of pascal's triangle :: ";
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        for (j = (n - i - 1); j > 0; --j)
        {
            cout << "  ";
        }
        cout << "1   ";
        for (j = 0, value = 1; j < i; ++j)
        {
            value *= ((double)(i - j) / (j + 1));
            cout << value << "   ";
        }
        cout << endl;
    }

    return 0;
}