#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 73, 4, 2, 54, 10};
    cout << "arranged in increasing order ::" << endl;
    sort(arr, arr + 5); //* it sorted in given range which you gave.
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
    cout << "arranged in decreasing order ::" << endl;
    sort(arr, arr + 5, greater<int>());
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}