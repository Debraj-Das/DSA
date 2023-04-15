#include <bits/stdc++.h>
using namespace std;

#define int long long int
void solve();

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1 ;
    // cin>>t ;
    while(t--) solve();
    return 0;
}


// Gobal variable for the dynamic programming problem 
// This approach is called top down approach or memorised approach

const int N = 100;
int v[N], w[N], W, n, memo[N][100001];


// it returns the maximum value total value
int knapsack(int index, int weight)
{
    // Base case
    if (index >= n)
        return 0;

    // memoissation part
    int &ans = memo[index][weight]; // ans referrence to memo[index][weight]
    if (ans != -1)
        return ans;

    // combination two idea by taking and not taking the item , and then taking the maximum

    // do not take the item
    ans = knapsack(index + 1, weight);
    // take the item at index
    if (w[index] + weight <= W)
        ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));

    return ans;
}



void solve()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    memset(memo, -1, sizeof(memo));
    cout << knapsack(0, 0);

    return ;
}