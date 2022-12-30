#include <iostream>
using namespace std;

int main()
{
    register long long int *arr;   //? variable declearation
    register int i, j, no_digit;

    cout << "Enter the initial input number :: ";  //~ intialisation of arrays
    cin >> i;
    const int n = i;
    arr = new long long int[n];
    cout << "Enter the input :: " << endl;
    for (i = 0; i < n; ++i)
    {
        cout << (i + 1) << ") ";
        cin >> arr[i];
    }

    cout << "\nEnter the no of digit you want to see :: ";  //* computed the vaules and display it
    cin >> no_digit;
    cout << "\nFibencci sequence is :: " << endl;
    for (i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    for (register long long int sum; no_digit > n; ++i, --no_digit)
    {
        if (i == n)
            i = 0;
        for (j = 0, sum = 0; j < n; ++j)
            sum += arr[j];
        arr[i] = sum;
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr ;
    return 0;
}

// long long int sum_arr(long long int arr[], int n)  //* you do by function or by directly.
// {

//     register long long int sum = 0;
//     for (register int i = 0; i < n; ++i)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }