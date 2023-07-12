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
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int max_sub_array(int arr[], int n, int k)
{
    int sum, i;
    for (i = 0, sum = 0; i < k; ++i)
        sum += arr[i];
    int max = sum;
    for (int j = 0; i < n; ++i, ++j)
    {
        sum += (arr[i] - arr[j]);
        if (sum > max)
            max = sum;
    }
    return max;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // try to find max subarray
    int max = max_sub_array(arr, n, k);
    cout << max;
    return;
}
