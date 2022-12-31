#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) 
{
        unordered_map<char,int> a ;
        int i ;
        for(i = 0 ; s[i];++i)
        {
           if(a.count(s[i])==0)
           a[s[i]] = 1 ;
           else
           ++a[s[i]];
        }
        for(i = 0 ; s[i]; ++i)
        {
            if(a[s[i]]==1)
            return i ;
        }
        return -1 ;
}

int main()
{
    
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
    string s ;
	cin >> t;
	while (t--)   // solve the problem inside of drive function for test cases.
    {
        cin>>s ;
        cout<<firstUniqChar(s)<<endl;
    }
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}