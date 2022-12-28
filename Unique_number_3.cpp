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

void find_unique_number(int arr[], int n)
{
    int i, j,x , sum_arr[32];
    //* fill the all element of sum_arr by zero
    for (i = 0; i < 32; ++i)
        sum_arr[i] = 0;

    // # calculated number of 1 in sum_arr
    for (i = 0; i < n; ++i)
    {
        for ( j = 0 , x =arr[i]; x; ++j, x >>= 1)
            if (x & 1)
                sum_arr[j]++;
    }
    //* calculated the unique number and here j variable use for find number
    for (i = 32, j = 0; i; --i)
    {
        j <<= 1;
        if (sum_arr[i - 1] % 3)
            j += 1;
    }
    cout << j << endl;
    return;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    find_unique_number(arr, n);
    return;
}
