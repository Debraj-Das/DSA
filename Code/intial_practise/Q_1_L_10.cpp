#include <iostream>

using namespace std;

int main()
{
    int no_rows, no_clomns, i, j;
    cout << "Enter no of rows and clomns :: ";
    cin >> no_rows >> no_clomns;
    for (i = 0; i < no_rows; ++i)
    {
        for (j = 0; j < no_clomns; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}