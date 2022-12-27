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

void first_nagative_number_in_subarray(int arr[], int n, int k)
{
    for (int i = 0, j = -1; i < (n - k + 1); ++i)
    {
        //# try to finding next native number if i > j
        if (i > j)
            while (++j < n)
                if (arr[j] < 0)
                    break;
        //# if j is present in window then print or print zero
        if ((i + k) > j)
            cout << arr[j] << endl;
        else
            cout << 0 << endl;
    }
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // try to find max subarray
    first_nagative_number_in_subarray(arr, n, k);
    return;
}
