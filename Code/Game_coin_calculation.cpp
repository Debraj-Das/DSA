#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int T , n , a , b ;
    cin >> T;
while (T--)
    {
        cin>>n>>a>>b;
        if(a<=b)
        {
            if(n%a)
            cout<<(n/a+1)<<endl;
            else
            cout<<(n/a)<<endl;
        }
        else
        cout<<1<<endl;
    }
return 0 ;
}