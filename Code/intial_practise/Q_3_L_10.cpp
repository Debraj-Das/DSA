#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "\nEnter the pattern height :: ";
    cin >> num;
    for (register int i = 1, j; i <= num; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}