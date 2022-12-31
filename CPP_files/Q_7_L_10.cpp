#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of the half pyramid :: ";
    cin >> n;
    for (register int i = n, j; i > 0; --i)
    {
        for (j = 1; j <= i; ++j)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}