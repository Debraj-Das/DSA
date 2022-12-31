#include <iostream>
#include <iomanip> //* Needed to do formatted I/O

using namespace std;

int main()
{
    cout << "\n\n Formatting the output :\n";
    cout << "----------------------------\n";

    double pi = 3.14159265;           //# this is floating point number
    
    cout << fixed << setprecision(4); //$ number is set to display with 4 decimal places
    cout << " The value of pi : " << pi << endl;
    cout << " The value of pi 4 decimal place of total width 8   : |" << setw(8) << pi << "|" << endl; //@ setw() sets the total width
    cout << " The value of pi 4 decimal place of total width 10  : |" << setw(10) << pi << "|" << endl;

    cout << setfill('-'); //# setfill() sets to fill the blanks with specified character
    cout << " The value of pi 4 decimal place of total width 8   : |" << setw(8) << pi << "|" << endl;
    cout << " The value of pi 4 decimal place of total width 10  : |" << setw(10) << pi << "|" << endl;

    cout << scientific; //# set value in scientific format with exponent
    cout << " The value of pi in scientific format is : " << pi << endl;

    bool done = false; //@ this is boolean variable
    cout << " Status in number : " << done << endl;
    cout << boolalpha; //# set output in alphabet true or false
    cout << " Status in alphabet : " << done << endl;
    cout << endl;
    
    return 0;
}
