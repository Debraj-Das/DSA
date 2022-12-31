#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of panlindromic pattern :: ";
    cin >> n;
    for (int i = 1, j; i <= n; ++i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << "  ";
        }
        for (j = i; j; --j)
        {
            cout << j<<" ";
        }
        for (j += 2; j <= i; ++j)
        {
            cout <<j<<" ";
        }

        cout << endl;
    }

    return 0;
}