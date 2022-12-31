// This program calculate of volune of a sphere
#include <iostream>

using namespace std ;

#define pi 3.1415926536

int main()
{
     double radius ;
     cout<<"Enter the radius of sphere :: ";
     cin>> radius ;
     cout<<"\nVolume of a Sphere of radious "<<radius<<" is "<<((4*pi*radius*radius*radius)/3)
          <<endl ;
     return 0 ;
}