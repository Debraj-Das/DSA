/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
void solve();

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

    int t = 1;
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int rain_water_trapping(int arr[], int n)
{
    int height[n], i, temp_max;
    for (i = 0, temp_max = arr[0]; i < n; ++i)
        height[i] = temp_max = max(temp_max, arr[i]);
    for (i = n - 1, temp_max = arr[n - 1]; i >= 0; i--)
        height[i] = min(height[i], temp_max = max(temp_max, arr[i]));
    for (i = 0, temp_max = 0; i < n; i++)
        temp_max += (height[i] - arr[i]);

    return temp_max;
}

void solve()
{
  int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout<<rain_water_trapping(arr,n)<<endl;

    return;
}