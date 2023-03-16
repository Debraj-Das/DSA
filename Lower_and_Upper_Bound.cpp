/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
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
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int lower_Bound(int arr[], int n, int key)
{
    // Implement Lower bound of key if not found return -1 ;
    int s = 0, e = n - 1, key = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            key = mid, e = mid - 1;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return key;
}

int upper_Bound(int arr[], int n, int key)
{
    // Implement Upper bound of key if not found return -1 ;
    int s = 0, e = n - 1, key = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            key = mid, s = mid + 1;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return key;
}

void solve()
{
    int n, key;
    cin >> n >> key;
    int arr[n];
    f(0, n) cin >> arr[i];
    cout << lower_Bound(arr, n, key) << el;
    cout << upper_Bound(arr, n, key) << el;
    return;
}
