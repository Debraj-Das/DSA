/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

int solveS(int n, vector<int> nums)
{
    nums[0] = (nums[0] + n) % n;
    for (int i = 1; i < n; i++)
        nums[i] = (nums[i] + (nums[i - 1] + n) % n) % n;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0, j = 1; i < n; i = j)
    {
        while (j < n && nums[i] == nums[j])
            j++;
        if ((j - i) > 1)
            ans += (j - i) * (j - i - 1) / 2;
        else if (nums[i] == 0)
            ans++;
    }
    return ans;
}

void solve()
{
    vector<int> nums = {4, 5, 0, 4 , 2};
    int n = nums.size();
    cout << solveS(n, nums) << el;

    return;
}