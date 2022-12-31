#include <iostream>

using namespace std;

int main()
{
    int n, i, j, k, h;
    double value;
    cout << "Enter no of zig-zag line :: ";
    cin >> n;
    cout << "Enter the hight of zig-zag :: ";
    cin >> h;
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (j == 0)
            {
                for (k = 2 * (h - i - 1); k > 0; --k)
                    cout << " ";
                cout << "*";
            }
            else if ((j % 2) == 1)
            {
                for (k = (4 * i - 1); k > 0; --k)
                    cout << " ";
                if (k == 0)
                    cout << "*";
            }
            else
            {
                for (k =( 4 * (h - 1 - i)-1); k > 0; --k)
                    cout << " ";
                if (k == 0)
                    cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}