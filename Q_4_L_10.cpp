#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the of Inverted half pyramid :: ";
    cin >> n;
    for (register int i = n, j; i > 0; i--)
    {
        for (j = 0; j < i; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}