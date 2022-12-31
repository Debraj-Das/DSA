#include <iostream>
#include <cmath>

using namespace std;
#define dcr 0.01745427 // Pi/180=3.14159/180 , it is converter factor
                       // for degree to radian

int main()
{
     double d, la1, la2, lo1, lo2, er;
     cout << "\n\n Print the the distance between two points on the surface of earth:" << endl
          << "------------------------------------------------------------------" << endl
          << " Input the latitude of coordinate 1: ";
     cin >> la1;
     cout << " Input the longitude of coordinate 1: ";
     cin >> lo1;
     cout << " Input the latitude of coordinate 2: ";
     cin >> la2;
     cout << " Input the longitude of coordinate 2: ";
     cin >> lo2;
     la1 = la1 * dcr;
     la2 = la2 * dcr;
     lo1 = lo1 * dcr;
     lo2 = lo2 * dcr;
     d = 6371.01 * acos((sin(la1) * sin(la2)) + (cos(la1) * cos(la2) * cos(lo1 - lo2)));
     // multiple 6371.01 for convert to Kilometers
     cout << " The distance between those points is: " << d << " Kilometer" << endl;
     return 0;
}
