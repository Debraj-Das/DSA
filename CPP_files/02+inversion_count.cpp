#include <iostream>
#include <vector>
using namespace std;

// helper method
int merge(vector<int> &array, int s, int e)
{
	int i = s;
	int m = (s + e) / 2;
	int j = m + 1;

	vector<int> temp;

	int cnt = 0;

	while (i <= m and j <= e)
	{
		if (array[i] < array[j])
		{
			temp.push_back(array[i]);
			i++;
		}
		else
		{
			cnt += (m - i + 1);
			temp.push_back(array[j]);
			j++;
		}
	}

	// copy rem elements from first array
	while (i <= m)
	{
		temp.push_back(array[i++]);
	}

	// or copy rem elements from second array
	while (j <= e)
	{
		temp.push_back(array[j++]);
	}

	// copy back the eleemtns from temp to original array
	int k = 0;
	for (int idx = s; idx <= e; idx++)
	{
		array[idx] = temp[k++];
	}
	return cnt;
}

// sorting method
int inversion_count(vector<int> &arr, int s, int e)
{
	// base case
	if (s >= e)
	{
		return 0;
	}
	// rec case
	int mid = (s + e) / 2;
	int C1 = inversion_count(arr, s, mid);
	int C2 = inversion_count(arr, mid + 1, e);
	int CI = merge(arr, s, e);
	return C1 + C2 + CI;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int s = 0;
	int e = arr.size() - 1;
	cout << inversion_count(arr, s, e) << endl;

	cout << endl;
	return 0;
}
