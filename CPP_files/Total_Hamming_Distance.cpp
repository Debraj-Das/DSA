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

int hammingDis(int x, int y)
{
    x ^= y;
    for (y = 1; (x & 1) == 0; ++y)
        x >>= 1;
    return y;
}

int totalHammingDistance(vector<int> nums)
{
    int total = 0;
    const int n = nums.size();
    for (int i = 0, j; i < n; ++i)
        for (j = i + 1; j < n; ++j)
            total += hammingDis(nums[i], nums[j]);
    return total;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        nums.push_back(x);
    }
    cout << totalHammingDistance(nums) << endl;
    return;
}
