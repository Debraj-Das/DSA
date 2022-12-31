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

int Largest_Subarray_of_sum_K(int arr[], int n, int k)
{
    long long int sum = 0;
    int max_size = 0;
    for (int i = 0, j = 0; j < n; ++j)
    {
        sum += arr[j];
        if ((sum == k) && (max_size < (j - i + 1)))
            max_size = (j - i + 1);
        else
            while (sum > k)
            {
                sum -= arr[i];
                ++i;
            }
    }
    return max_size;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    //* try to find count occurrences of Anagrams of a given string
    cout << Largest_Subarray_of_sum_K(arr, n, k) << endl;
    return;
}
