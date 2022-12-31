#include <iostream>
using namespace std;

int sum_arr(long long int arr[], int n)
{
    int sum, i;
    for (i = 0, sum = 0; i <= n; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int sum_of_last_digit(long long int arr[], int n)
{
    int sum, i;
    for (i = 0, sum = 0; i < n; ++i)
    {
        sum += (arr[i] % 10);
        arr[i] /= 10;
    }
    return sum + arr[n];
}

int main()
{
    register long long int value, digit, *arr;
    register int i, n;
    while (true)
    {
        cout << "\nEnter the no of binary number :: ";
        cin >> n;
        if (n <= 0)
            break;

        arr = new long long int[n + 1];
        for (i = 0; i < n; ++i)
        {
            cout << (i + 1) << ") ";
            cin >> arr[i];
        }

        for (digit = 1, arr[n] = 0, value = 0; sum_arr(arr, n); digit *= 10)
        {
            i = sum_of_last_digit(arr, n);
            value += ((i % 2) * digit);
            arr[n] = i / 2;
        }
        cout << "\nValue of sum of those binary number is :: " << value << endl;

        delete[] arr;
        cout << "\nComputation again start.if you want to enter Zero." << endl;
    }
    cout << "\nProcess is finished\n"
         << endl;
    return 0;
}