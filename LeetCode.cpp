/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
//	cin >> t;
    while (t--) solve();  // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    
    
    return ;
}

// Two sum Problem Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int , int> comp ;
       const int n = nums.size() ;
       for(int i = 0 ; i<n ;++i )
       {
           if(comp.find(nums[i])==comp.end())
           comp[target-nums[i]] = i ;
           else 
           return {comp[nums[i]] , i};
       } 
       return {};
    }
};

