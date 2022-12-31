/*
	 অভিজ্ঞতা একটি কঠিন শিক্ষক,
	 সে প্রথমে তোমার পরীক্ষা নেয় এবং
	 পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>

using namespace std;

void Solve() ;

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
	while (t--) Solve();  // Solve the problem inside of drive function for test cases.

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}

void DNF_arrag(int arr[],int n, int ele)
{
    /*
    * psudo code for Ducth Nation Flag algorithm
    check value of arr[mid] with element
    if < then swap arr[low] and arr[mid] , and low++ , mid++
    else if == then mid++
    else then swap arr[high] and arr[mid] , and high-- 
    */
    int low = 0 , mid = 0, high = n-1 , temp ;
    while(mid <high)
    {
        if(ele>arr[mid])
        {
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            mid++;
            low++;
        }
        else if (arr[mid]==ele)
        mid++;
        else
        {
            temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }
    return ;
}

void Solve() 
{
   int n ;
   cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    // I want arrenge the arr according a certain element
    int element ;
    cin>>element ;
    DNF_arrag(arr , n , element);
    for(int i =0 ; i<n;++i)
    cout<<arr[i]<<endl;

    return ;
}
