#include <iostream>
using namespace std;

int main()
{
  register long long int n;
  register int sum_of_digit;
  cout<<"Enter the number :: ";
  cin>>n ;
  for (sum_of_digit = 0; n; n /= 10)
    sum_of_digit += n % 10;
  cout << "sum of the enter digit is " << sum_of_digit << endl;
  return 0;
}