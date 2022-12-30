#include <iostream>
#include <cmath>

using namespace std;
#define pi 3.141593

int main()
{
     int no_of_side;
     double length_of_side;
     cout << "Print the area of a polygon:" << endl
          << "--------------------------" << endl
          << "Input the number of sides of the polygon:";
     cin >> no_of_side;
     cout << "Input the length of each side of the polygon:";
     cin >> length_of_side;
     cout << "The area of the polygon is: "
          << ((no_of_side * length_of_side * length_of_side) / (4 * tan(pi / no_of_side)))
          << endl;
     return 0;
}