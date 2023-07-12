#include <iostream>
#include <climits>

using namespace std ;


int main()
{
    cout<<"Minimum vaule of C++ is "<<INT_MIN<<endl ;
    cout<<"Maximum vaule of C++ is "<<INT_MAX<<endl ;
    int n , i ;
    cout<<"Enter the size of array :: ";
    cin>>n ;
    int *arr = new int[n];
    cout<<"Enter the element of array ::"<<endl ;
    for(i = 0 ; i <n ; ++i)
    {
        cout<<(i+1)<<") ";
        cin>>arr[i];
    }
    int max , min ;
    for(i =0 , max = arr[0], min = arr[0]; i <n ; ++i)
    {
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];
    }
    cout<<"Minimum in array is "<<min<<endl ;
    cout<<"Maxmimum in array is "<<max<<endl ;
    delete[] arr ;
    return 0 ;
}