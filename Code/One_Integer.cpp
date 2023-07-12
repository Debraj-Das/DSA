#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i:nums)
    pq.push(i);

    int x , sum = 0 ;
     while (pq.size() > 1)
    {
        x = pq.top() ;
        pq.pop();
        x+= pq.top();
        pq.pop();
        pq.push(x);
        sum+=x ;
    }
    return sum ;
}


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
    // cin >> t;
    while (t--)
        cout<<solve({1, 3, 2, 4, 5,3 })<<endl; // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
