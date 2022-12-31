#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of the half pyramid :: ";
    cin >> n;
    for (int i = 0, j; i < n; ++i)
    {
        for (j = n; j > i; --j)
        {
            cout << (i+1) << " ";
        }
        cout << endl;
    }

    return 0;
}