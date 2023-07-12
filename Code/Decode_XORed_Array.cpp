#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first)
{
    vector<int> arr = {first};
    for(int x:encoded)
    {
        first = first^x;
        arr.push_back(first);
    }
    return arr ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> encoded , arr;
    int n ;
    cin>>n;
    for(int i =0 , x; i<n;++i)
    {
        cin>>x;
        encoded.push_back(x);
    }
    cin>>n;
    arr = decode(encoded,n);
    for(int x:arr)
    cout<<x<<' ';
    cout<<endl;
    return 0;
}