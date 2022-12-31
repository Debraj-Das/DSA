#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k)
{
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[k-1];
}

int main()
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
    // cin >> t;
    while (t--) // solve the problem inside of drive function for test cases.
    {
        vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        cout << findKthLargest(v, 4) << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}