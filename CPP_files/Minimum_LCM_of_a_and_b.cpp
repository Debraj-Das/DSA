#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int T , n , sqrN , i ;
    cin >> T;
while (T--)
    {
        cin>>n ;
        sqrN = sqrt(n) + 1;
        for(i = 2 ; i < sqrN ; ++i)
        {
            if(n%i == 0)
            break;
        }
        if(i < sqrN)
            i = (n/i);
        else 
            i = 1 ;
        cout<<i<<' '<<(n-i)<<endl ;
    }
return 0 ;
}