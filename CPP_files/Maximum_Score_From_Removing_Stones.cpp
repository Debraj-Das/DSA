#include <bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c)
{
    int diff , res ;
    if (a > b)
    {
        diff = a;
        a = b;
        b = diff;
    }
    if (b > c)
    {
        diff = b;
        b = c;
        c = diff;
    }
    diff = (a + b)-c;
    if(diff>0)
    {
        res = (diff/2) ;
        res+=c ;
    }
    else
    {
        res = (a+b) ;
    }
    return res ;
}

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

    int t = 1 , a ,b , c;
    cin >> t;
    while (t--)   // solve the problem inside of drive function for test cases.
    {
        cin>>a>>b>>c ;
        cout<<maximumScore(a,b,c )<<endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}