#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of half pyramid :: ";
    cin >> n;
    for (int i = 1, j; i <= n; ++i)
    {
        for (j = 0; j < (n - i); ++j)
        {
            cout << "  ";
        }
        for (j = 0; j < i; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}