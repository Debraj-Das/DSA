#include <bits/stdc++.h>
using namespace std;

int unique_number(vector<int> arr)
{
    int unq = 0 ;
    for(int x:arr)
    unq ^= x ;
    return unq ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T ;
    cin >> T;
    vector<int> arr ;
    for(int i = 0 , n ;i<T ; ++i)
    {
        cin>>n;
        arr.push_back(n);
    }
    cout<<unique_number(arr)<<endl;
    return 0;
}