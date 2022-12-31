#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Convert kilometers perhour to miles per hour :"<<endl
        <<"---------------------------------------"<<endl;
    double km_per_hour ;
    cout<<"Input the distance in kilometer : ";
    cin>>km_per_hour ;
    cout<<"The "<<km_per_hour<<"Km./hr. means "<<(0.62137119*km_per_hour)<<" Miles/hr."<<endl;

    return 0;
}