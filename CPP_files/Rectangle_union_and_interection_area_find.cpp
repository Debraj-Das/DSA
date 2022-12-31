#include <iostream>
using namespace std;

void Sort(int arr[])
{
    int i, j, temp;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    return;
}
int main()
{
    int t, in_area, totalarea, x[4], y[4];
    cin >> t;
    while (t--)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        cin >> x[2] >> y[2] >> x[3] >> y[3];

        totalarea = (x[1] - x[0]) * (y[1] - y[0]) + (x[3] - x[2]) * (y[3] - y[2]);

        if (x[2] > x[1] || x[3] < x[0] || y[2] > y[1] || y[3] < y[0])
            in_area = 0;
        else
        {
            Sort(x);
            Sort(y);
            in_area = (x[2] - x[1]) * (y[2] - y[1]);
        }
        cout << in_area << ' ' << totalarea - in_area << endl;
    }
    return 0 ;
}
