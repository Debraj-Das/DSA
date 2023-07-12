#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the hight of 1-0 pattern :: ";
    cin >> n;
    for (register int i = 1, j; i <= n; ++i)
    {
        for (j = 0; j < i; ++j)
            cout << ((i + j) % 2) << " ";
        cout << endl;
    }
    return 0;
}