#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of the half pyramid :: ";
    cin >> n;
    for (int i = 1, j; i <= n; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}