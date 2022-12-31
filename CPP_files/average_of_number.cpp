#include <iostream>

using namespace std;

int main()
{
  /*
   int *arr, n;  //* first algorithm of finding average of n number.
   cout << "How many numbers u want to enter :: ";
   cin >> n;
   arr = new int[n];
   for (int i = 0; i < n; ++i)
   {
     cout << "\nEnter number " << (i + 1) << " :: ";
     cin >> arr[i];
   }
   cout << endl;
   int sum = 0;
   for (int i = 0; i < n; ++i)
   {
     sum += arr[i];
   }
   cout << "\nSum of " << n << "Numbers :: " << sum << endl;
   cout << "\nMverage of " << n << " Numbers :: " << ((double)sum) / n << endl;
   delete arr ;
   */

  int n, sum = 0; //~ second algorithm of finding average of any numbers.
  cout << "How many numbers u want to enter :: ";
  cin >> n;
  for (int i = 0, z; i < n; ++i)
  {
    cout << "\nEnter number " << (i + 1) << " :: ";
    cin >> z;
    sum += z;
  }
  cout << "\nSum of " << n << "Numbers :: " << sum << endl;
  cout << "\nMverage of " << n << " Numbers :: " << ((double)sum) / n << endl;

  return 0;
}