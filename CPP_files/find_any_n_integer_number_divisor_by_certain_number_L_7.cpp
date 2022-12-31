#include <iostream>

using namespace std;

int main()
{
    register int num_range, divisor;
    cout << "\nEnter a number which you want to analished :: ";
    cin >> num_range;
    cout << "Enter the divisor :: ";
    cin >> divisor;
    for (register int i = 1; i <= num_range; ++i)
    {
       cout<< ((i % 10 == 0) ? "\n" : " ") ;
        if (i % divisor == 0)
            continue;
        cout << i;
    }
    cout << endl;
    return 0;
}