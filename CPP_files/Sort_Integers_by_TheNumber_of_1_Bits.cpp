#include <bits/stdc++.h>
using namespace std;

int Count_bit(int n)
{
    int count = 0;
    while (n)
    {
        n = (n & (n - 1));
        ++count;
    }
    return count;
}

vector<int> sortByBits(vector<int> arr)
{
    vector<int> bit_arr;
    for (int x : arr)
        bit_arr.push_back(Count_bit(x));
        // bubble sort algorithm for sorting arr as respect to bit_arr
    for (int i = 0, j, temp, n = arr.size(); i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if ((bit_arr[j] > bit_arr[j + 1]) || ((bit_arr[j] == bit_arr[j + 1]) && (arr[j] > arr[j + 1])))
            {
                temp = bit_arr[j];
                bit_arr[j] = bit_arr[j + 1];
                bit_arr[j + 1] = temp;

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    return arr;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1, n;
    vector<int> arr;
    cin >> t;
    while (t--) // Count_bit_hack the problem inside of drive function for test cases.
    {
        cin >> n;
        for (int i = 0, x; i < n; ++i)
        {
            cin >> x;
            arr.push_back(x);
        }
        arr = sortByBits(arr);
        for (int x : arr)
            cout << x << ' ';
        cout << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
