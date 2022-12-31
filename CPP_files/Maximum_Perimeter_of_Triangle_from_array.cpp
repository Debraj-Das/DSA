//{ Driver Code Starts
// Efficient solution to find
// out maximum perimeter triangle which
// can be formed using the elements
// of the given array
#include <iostream>
#include <algorithm>

using namespace std;

// Function to find out maximum perimeter
int maxPerimeter(int arr[], int n);


// Driver Program
int main()
{
	int t,n;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << maxPerimeter(arr,n) << endl;
    }
	return 0;
}


// } Driver Code Ends

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
    return ;
}


int maxPerimeter(int arr[], int n){

    // Complete the function
    quickSort(arr, 0, n - 1);
    for(int i = n-1 ; i > 1 ; --i)
    {
        if(arr[i]<(arr[i-1]+arr[i-2]))
        return (arr[i]+arr[i-1]+arr[i-2]);
    }
    return -1 ;
}
