#include <iostream>

using namespace std;

int main()
{
    register int i, sum ;
    cout << "\nEnter a number for summation 1 to this number\n\t::";
    cin >> i;
   sum = 0 ;
   ++i ;
   while(--i)   //* by while loop
   {
     sum+= i ;
   }
    // const int n = i;   //* by for loop
    // for (i = 1, sum = 0; i <= n; ++i)
    // {
    //     sum += i;
    // }
    cout << "\nSum of n integer number is " << sum << endl;

    return 0;
}