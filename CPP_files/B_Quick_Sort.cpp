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

int disorder_number(int arr[], int n)
{
    int no_of_disorder = 0;
    for (int i = 0; i < n; ++i)
        if ((i + 1 - no_of_disorder) != arr[i])
            ++no_of_disorder;
    return no_of_disorder;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int no_of_disorder = disorder_number(arr, n);
    
    if(no_of_disorder==0)
        cout<< no_of_disorder <<endl; 
    else if(no_of_disorder%k == 0)
        cout<< (no_of_disorder/k) <<endl; 
    else
        cout<< ((no_of_disorder/k)+1) <<endl; 

    return;
}