#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if(n&(n-1))
    return false ;
    else
    return true ;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n ;
    cin>>n;
    if(isPowerOfTwo(n))
    cout<<n<<" is a power of Two"<<endl;
    else
    cout<<n<<" is not a power of Two"<<endl;
    return 0 ;
}