#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Find the any triangle using Heron's Formula:" << endl
         << "----------------------------------------" << endl;
    double a, b, c;
    cout << "Input the length of 1st side of the triangle  : ";
    cin >> a;
    cout << "Input the length of 2nd side of the triangle : ";
    cin >> b;
    cout << "Input the length of 3rd side of the triangle : ";
    cin >> c;
    
    double s = (a + b + c) / 2;
    double area = sqrt((s * (s - a) * (s - b) * (s - c)));
    cout << "The area of the triangle is : " << area << endl;

    return 0;
}