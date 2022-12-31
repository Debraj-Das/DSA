#include <iostream>

using namespace std;

int main()
{
    register int n, i, j;
    cout << "\nEnter the hight of panlindromic pattern :: ";
    cin >> n;
    for (i = 1, j; i <= n; ++i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << " ";
        }
        cout << "*";
        for (j = (i - 1); j; --j)
        {
            cout << " ";
        }
        for (j += 2; j < i; ++j)
        {
            cout << " ";
        }
        if (j == i)
            cout << "*";
        cout << endl;
    }
    for (i = n, j; i > 0; --i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << " ";
        }
        cout << "*";
        for (j = (i - 1); j; --j)
        {
            cout << " ";
        }
        for (j += 2; j < i; ++j)
        {
            cout << " ";
        }
        if (j == i)
            cout << "*";
        cout << endl;
    }

    return 0;
}