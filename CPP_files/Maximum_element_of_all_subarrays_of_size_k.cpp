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

void Maximum_element_of_all_subarrays_of_size_k(int arr[], int n, int k)
{
    for (int i = 0, max_index = -1 , j ; i + k <= n; ++i)
    {
        if(arr[max_index]<arr[i+k-1])
            max_index = i+k-1 ;
        else if (max_index < i)
        {
            max_index = i;
            for (j = i; j < i+k; ++j)
            if (arr[j] > arr[max_index])
                    max_index = j;
        }
        cout << arr[max_index] <<' ';
    }
    cout<<endl;
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // # try to find max element in subarray
    Maximum_element_of_all_subarrays_of_size_k(arr, n, k);
    return;
}
