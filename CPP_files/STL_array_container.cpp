#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    array<int, 6> arr = {1, 24, 3, 48, 5, 15}; //* array of STL

    // for(int i =0 ; i<arr.size();++i)
    // cout<<arr[i]<<' ';
    for (int i : arr) // # for each loop for stl container
        cout << i << endl;
    cout << endl;

    sort(arr.begin(), arr.end());
    for (int i : arr)
        cout << i << endl;
    cout << endl;

    arr.fill(73);
    for (int i : arr)
        cout << i << endl;

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}