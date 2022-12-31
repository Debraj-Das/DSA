/*
	 অভিজ্ঞতা একটি কঠিন শিক্ষক,
	 সে প্রথমে তোমার পরীক্ষা নেয় এবং
	 পরে তার পাঠ দেয়।
*/
#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) 
{
      x = (x^y);
      y = 0;
      while(x)
      {
        x = (x&(x-1));
        ++y ;
      }
      return y;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1 , x , y;
	cin >> t;
	while (t--)   // solve the problem inside of drive function for test cases.
    {
        cin>>x>>y ;
        cout<<hammingDistance(x,y)<<endl;
    }
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}
