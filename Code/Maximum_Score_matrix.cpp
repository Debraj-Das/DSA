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

#include <bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid)
{
    int sum, m = grid.size(), n = grid[0].size(), i, j;
    //* move according to row
    for (i = 0; i < m; ++i)
        if (grid[i][0] == 0)
            for (j = 0; j < n; ++j)
                grid[i][j] ^= 1;
    //* move according to cloumn
    for (i = 0; i < n; ++i)
    {
        for (j = 0, sum = 0; j < m; ++j)
            if (grid[j][i])
                ++sum;
        if (sum < (n - sum))
            for (j = 0; j < m; ++j)
                grid[j][i] ^= 1;
    }
    //# sum the all element according to row
    for (i = 0, sum =0; i < m; ++i)
    {
        int temp = 0;
        for (j = 0; j < n; ++j)
        {
            temp <<= 1;
            if (grid[i][j])
                temp += 1;
        }
        sum += temp ;
    }
    return sum;
}

void solve()
{
    cout<<matrixScore({{0, 0 , 1 ,1 },{1 , 0 , 1 , 0},{1 , 1, 0 , 0}})<<endl;
    return ;
}
