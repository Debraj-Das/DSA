#include <iostream>
#include <climits> //* integer limits in header file

using namespace std;

int main()
{
    cout << "\n\n Check the upper and lower limits of integer :\n"
         << "--------------------------------------------------\n"
         << " The maximum limit of int data type :                  " << INT_MAX << endl
         << " The minimum limit of int data type :                  " << INT_MIN << endl
         << " The maximum limit of unsigned int data type :         " << UINT_MAX << endl
         << " The maximum limit of long long data type :            " << LLONG_MAX << endl
         << " The minimum limit of long long data type :             " << LLONG_MIN << endl
         << " The maximum limit of unsigned long long data type :   " << ULLONG_MAX << endl
         << " The Bits contain in char data type :                  " << CHAR_BIT << endl
         << " The maximum limit of char data type :                 " << CHAR_MAX << endl
         << " The minimum limit of char data type :                 " << CHAR_MIN << endl
         << " The maximum limit of signed char data type :          " << SCHAR_MAX << endl
         << " The minimum limit of signed char data type :          " << SCHAR_MIN << endl
         << " The maximum limit of unsigned char data type :        " << UCHAR_MAX << endl
         << " The minimum limit of short data type :                " << SHRT_MIN << endl
         << " The maximum limit of short data type :                " << SHRT_MAX << endl
         << " The maximum limit of unsigned short data type :       " << USHRT_MAX << endl
         << endl;

    return 0;
}