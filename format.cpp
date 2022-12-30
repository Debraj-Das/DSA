#include <iostream>
#include <iomanip> //* Needed to do formatted I/O
using namespace std;

int main()
{
    cout << "Formatting the output :" << endl;
    cout << "----------------------------" << endl;

    double pi = 3.14159265;           // this is floating point number
    cout << fixed << setprecision(6); // number is set to display with 6 decimal places
    cout << " The value of pi : " << pi << endl;
    cout << " The value of pi 6 decimal place of total width 8   : |" << setw(8) << pi << "|" << endl; // setw() sets the total width
    cout << " The value of pi 6 decimal place of total width 10  : |" << setw(10) << pi << "|" << endl;

    cout << setfill('-');            // setfill() sets to fill the blanks with specified character
    cout << " The value of pi 6 decimal place of total width 8   : |" << setw(8) << pi << "|" << endl;
    cout << " The value of pi 6 decimal place of total width 10  : |" << setw(10) << pi << "|" << endl;

    cout << scientific;             // set value in scientific format with exponent
    cout << " The value of pi in scientific format is : " << pi << endl;

    bool done = false;              // this is boolean variable
    cout << " Status in number : " << done << endl;
    cout << boolalpha;             // set output in alphabet true or false
    cout << " Status in alphabet : " << done << fixed << setprecision(4) << "\t" << pi << endl;

    int number = 30;
    cout << setbase(16) << "Vaule of number :: " << number << endl;

    return 0;
}
