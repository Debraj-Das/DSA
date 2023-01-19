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

vector<int> div_sub(int arr[], int n)
{
    int i, sum, x;
    unordered_set<int> store;
    for (i = 0, sum = 0; i < n; ++i)
    {
        sum += arr[i];
        x = sum % n;
        if (x == 0)
            return {0, i};
        else if (store.find(x) != store.end())
            break;
        else
        {
            store.insert(x);
            arr[i] = x;
        }
    }
    for (sum = 0; sum < i; ++sum)
        if (arr[sum] == x)
            break;
    return {sum + 1, i};
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> range = div_sub(arr, n);

    cout << (range[1] - range[0] + 1) << endl;
    for (int i = range[0]; i <= range[1]; ++i)
        cout << (i + 1) <<' ';
    
    return;
}

