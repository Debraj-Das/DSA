#include <iostream>
using namespace std;

int main()
{
    int T, n, r, c, x, y, i;
    bool **arr ;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> n >> r >> c >> x >> y;
        cin >> s;
        arr = (bool **)malloc(r * sizeof(bool *));
        for (i = 0; i < r; ++i)
            arr[i] = (bool *)calloc(c, sizeof(int));
        for (i = 0, x -= 1, y -= 1; i < n; ++i)
        {
            arr[x][y] = 1;
            switch (s[i])
            {
            case 'N':
                while (arr[x][y])
                    --x;
                break;
            case 'S':
                while (arr[x][y])
                    ++x;
                break;
            case 'E':
                while (arr[x][y])
                    ++y;
                break;
            case 'W':
                while (arr[x][y])
                    --y;
                break;
            }
        }
        for (i = 0; i < r; ++i)
            free(arr[i]);
        free(arr);
        cout << (x + 1) << ' ' << (y + 1) << endl;
    }
    return 0;
}