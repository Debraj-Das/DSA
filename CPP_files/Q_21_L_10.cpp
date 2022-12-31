#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cout << "Enter no of rows in Hollow butterfly pattern :: ";
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            ((j==0)||(j==(i-1)))?cout << "*":cout <<" ";
        }
        for (j = 2 * (n - i); j > 0; --j)
        {
            cout << " ";
        }
        for (j = 0; j < i; ++j)
        {
            ((j==0)||(j==(i-1)))?cout << "*":cout <<" ";
        }
        cout << endl;
    }
    for (i = n; i > 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            ((j==0)||(j==(i-1)))?cout << "*":cout <<" ";
        }
        for (j = 2 * (n - i); j > 0; --j)
        {
            cout << " ";
        }
        for (j = 0; j < i; ++j)
        {
            ((j==0)||(j==(i-1)))?cout << "*":cout <<" ";
        }
        cout << endl;
    }

    return 0;
}