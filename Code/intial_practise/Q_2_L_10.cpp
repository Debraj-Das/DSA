#include <iostream>

using namespace std;

int main()
{
    int no_row, no_clomn, i, j;
    cout << "\nEnter the no of row and clomn :: ";
    cin >> no_row >> no_clomn;
    for (i = 0; i < no_row; ++i)
    {
        for (j = 0; j < no_clomn; ++j)
        {
            if ((i == 0) || (i == (no_row - 1)) || (j == 0) || (j == (no_clomn - 1)))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}