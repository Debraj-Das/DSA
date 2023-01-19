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
	cin >> t;
    while (t--) solve();  // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

bool make_to_beautiful(int arr[],int n)
{
    if(arr[0]==arr[n-1])
    return false;
    else
    {
        if(arr[1]==arr[n-1])
        swap(arr[0],arr[1]);
        else
        swap(arr[0],arr[n-1]);
        return true;
    }
    return true;
}

void solve()
{
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    bool check = make_to_beautiful(arr,n);
    if(check)
    {
        cout<<"YES"<<endl;
        for(int i = 0 ; i <n ; ++i)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
    else
    cout<<"NO"<<endl;
    
    return ;
}
