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

vector<int> smallestRange(vector<vector<int>> nums)
{
    vector<pair<int, int>> v;
    for(int i = 0 , j ; i < nums.size(); i++)
        for(j = 0; j < nums[i].size(); j++)
            v.push_back({nums[i][j], i});
    
    sort(v.begin(), v.end());
    int i = 0, j = 0, n = v.size(), k = nums.size();
    int cnt[k] = {0} , lenth = 0  ;
    vector<int> ans = {v[0].first, v[n-1].first};
    for(i = 0 ; i < n ;i++)
    {
        while(j < n && lenth < k)
        {
            if(cnt[v[j].second] == 0)
                lenth++;
            cnt[v[j].second]++;
            j++;
        }
        if(lenth == k && ans[1] - ans[0] > v[j-1].first - v[i].first)
            ans = {v[i].first, v[j-1].first};
        
        cnt[v[i].second]--;
        if(cnt[v[i].second] == 0)
            lenth--;
    }
    return ans;
}

void solve()
{
    vector<int> ans = smallestRange({{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}});
    for(auto i : ans)
        cout << i << " ";
    return;
}