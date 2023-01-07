/*
	 অভিজ্ঞতা একটি কঠিন শিক্ষক,
	 সে প্রথমে তোমার পরীক্ষা নেয় এবং
	 পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

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
	cin >> t;
	while (t--) solve();  // solve the problem inside of drive function for test cases.

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}

int countTriplets(vector<int> nums) 
{
    const int n = nums.size();
    int triple = 0 ;
    for(int i = 0 ,j , k , x;i<n;++i)
        for(j = 0 ;j<n;++j)
        {
            x = (nums[i]&nums[j]);
            if(x)
            {
                for(k=0;k<n;++k)
                    if((x&nums[k])==0) triple++;
            }
            else
            triple+=n ;
        }
    return triple ;
}

void solve() 
{
    int n ,x;
    cin>>n;
    vector<int> nums ;
    for(int i=0;i<n;++i)
       {
         cin>>x ;
         nums.push_back(x);
       }
    cout<<countTriplets(nums)<<endl;
    return ;
}
