#include <iostream>

using namespace std;

int main()
{
    cout << "\nThe Size of (int) is " << sizeof(int) << endl
         << "The Size of (short int) is " << sizeof(short int) << endl
         << "The Size of (long int) is " << sizeof(long int) << endl
         << "The Size of (long long int) is " << sizeof(long long int) << endl
         << "The Size of (float) is " << sizeof(float) << endl
         << "The Size of (double) is " << sizeof(double) << endl
         << "The Size of (long double) is " << sizeof(long double) << endl
         << "The Size of (char) is " << sizeof(char) << endl
         << "The Size of (bool) is " << sizeof(bool) << endl
         << "The Size of (pointer) is " << sizeof(char *) << endl;

    return 0;
}