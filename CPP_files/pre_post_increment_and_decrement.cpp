#include <iostream>

using namespace std;

int main()
{
    register int n = 57 ;
    cout << "Display the operation of pre and post incremint and decrement :" << endl
         << "-----------------------------------------" << endl
         << "The is number is : " << n << endl;
    cout<< "After post increment by 1 the number is :" << (n++) << endl;
    cout<< "After pre increment by 1 the number is :" << (++n) << endl;
    cout<< "After increasing by 1 the number is : " << (n += 1) << endl;
    cout<< "After post decrement by 1 the number is : " << (n--) << endl;
    cout<< "After pre decrenent by 1 the number is : " << (--n) << endl;
    cout<< "After decreasing by 1 the number is : " << (n -= 1) << endl;
    cout<< endl;

    return 0;
}