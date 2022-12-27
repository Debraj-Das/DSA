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

int max_sub_array(int arr[], int n)
{
    /*
    Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

    Loop for each element of the array

    (a) max_ending_here = max_ending_here + a[i]
    (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
    (c) if(max_ending_here < 0)
            max_ending_here = 0
    return max_so_far
    */
    int max = INT_MIN;
    for (int i = 0, current_max = 0; i < n; ++i)
    {
        current_max += arr[i];
        if (current_max > max)
            max = current_max;
        if (current_max <= 0)
            current_max = 0;
    }
    return max;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // try to find max subarray
    int max = max_sub_array(arr, n);
    cout << max;
    return;
}
