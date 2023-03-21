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

int sum_of_subarray_is_Zero(int arr[], int n)
{
    unordered_map<int, int> store_sum;
    int sum = 0, max_size = 0;
    /* min size subarray size which sum of the element is zero is zero
     means not present the subarray*/
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        // if sum is Zero then length of subarray equal to that array part
        if (sum == 0)
            max_size = max(max_size, i + 1);
        // if sum is sum is equal to previous sum then (index - index_of_previous)
        else if (store_sum.find(sum) != store_sum.end())
            max_size = max(max_size, i - store_sum[sum]);
        // other then store inside the map
        else
            store_sum[sum] = i;
    }
    return max_size;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << sum_of_subarray_is_Zero(arr, n) << endl;

    return;
}