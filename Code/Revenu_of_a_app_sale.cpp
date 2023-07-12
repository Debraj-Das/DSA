#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    int arr[n];
    for(int i = 0 ; i<n;++i)
    cin>>arr[i];

    for(int i = 0 , j , tem ; i <n ;++i)
    {
        for(j = n-1 ; j > i ;  j--)
        {
            if(arr[j-1] < arr[j])
            {
                tem = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tem ;
            }
        }
    }

    int max_revenu = 0 ;
    for(int i = 0 , current_revenu ; i <n ; ++i)
    {
        current_revenu = (i+1)*arr[i] ;
        if(max_revenu < current_revenu)
        max_revenu = current_revenu ;
    }
    cout<<max_revenu<<endl ;
    return 0 ;
}