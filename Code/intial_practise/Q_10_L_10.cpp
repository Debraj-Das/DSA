#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "\nEnter the hight of the half pyramid :: ";
    cin >> n;
    for (int i = 1, j ,count = 1; i <= n; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            cout << count << " ";
            count++ ;
        }
        cout << endl;
    }

    return 0;
}