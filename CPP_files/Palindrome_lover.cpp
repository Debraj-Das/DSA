/*
	 অভিজ্ঞতা একটি কঠিন শিক্ষক,
	 সে প্রথমে তোমার পরীক্ষা নেয় এবং
	 পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

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

void solve()        //* this function show number is prefect or not
{
	int n , no_1 = 0 ;
    cin>>n ;
    int arr[n];
    for(int i =0 ; i<n;++i)
    {
        cin>>arr[i];
        arr[i] %=2 ;
        if(arr[i])
            ++no_1 ;
    }
    if((n%2)||((n%2==0)&&(no_1%2==0)))
    cout<<1<<endl;
    else
    cout<<0<<endl;
    
    return ;
}
