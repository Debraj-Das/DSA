#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array :: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the element of array ::" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << (i + 1) << ") ";
        cin >> arr[i];
    }
    // sorting by insertion sorting
    for(int i = 1 , j, current ; i < n ; ++i)
    {
        for(current = arr[i],j = (i-1);(arr[j]>current)&&(j>=0);j--)
        arr[j+1] = arr[j];
        arr[j+1] = current ;
    }
    cout<<"Array after sorted ::"<<endl;
    for(int i = 0 ; i<n;++i)
    cout<<arr[i]<<endl;

    delete[] arr;

    return 0;
}