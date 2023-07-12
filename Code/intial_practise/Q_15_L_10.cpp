#include <iostream>

using namespace std;

int main()
{
    register int n, i, j;
    cout << "\nEnter the hight of Hollow Diamond pattern :: ";
    cin >> n;
    for (i = 0, j; i < n; ++i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << "*";
        }
        for (j = i; j; --j)
        {
            cout << " ";
        }
        for (++j; j < i; ++j)
        {
            cout << " ";
        }
        for (j = (i) ? 0 : 1; j < (n - i); ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = (n - 1), j; i >= 0; --i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << "*";
        }
        for (j = i; j; --j)
        {
            cout << " ";
        }
        for (++j; j < i; ++j)
        {
            cout << " ";
        }
        for (j = (i) ? 0 : 1; j < (n - i); ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}