#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{

    time_t t = time(NULL);
    tm *tPtr = localtime(&t);

    cout << "\n\n Display the Current Date and Time :" << endl;
    cout << "----------------------------------------" << endl;

    cout << " Current Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) << endl;
    cout << " Current Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;

    cout <<" "<< (tPtr->tm_mday) << " ";
    switch ((tPtr->tm_mon) + 1)
    {
    case 1:
        cout << "January, ";
        break;
    case 2:
        cout << "February, ";
        break;
    case 3:
        cout << "March, ";
        break;
    case 4:
        cout << "April, ";
        break;
    case 5:
        cout << "May, ";
        break;
    case 6:
        cout << "June, ";
        break;
    case 7:
        cout << "July, ";
        break;
    case 8:
        cout << "August, ";
        break;
    case 9:
        cout << "September, ";
        break;
    case 10:
        cout << "October, ";
        break;
    case 11:
        cout << "November, ";
        break;
    case 12:
        cout << "December, ";
        break;
    }
    cout << (tPtr->tm_year) + 1900 << endl;

    cout << " weekday = ";
    switch ((tPtr->tm_wday))
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    }
    cout << endl;

    cout << " day of year = " << (tPtr->tm_yday) << endl;
    cout << " daylight savings = " << (tPtr->tm_isdst) << endl<<endl;

    return 0;
}
