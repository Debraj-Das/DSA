#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Compute quotient and remainder :"<<endl
        <<"---------------------------"<<endl;
    int dividend , divisor ;
    cout<<"Input the dividend : ";
    cin>>dividend;
    cout<<"Input the divisor : ";
    cin>>divisor;
    cout<<"The quotient of the division is :"<<(dividend/divisor)<<endl;
    cout<<"The remainder of the division is : "<<(dividend%divisor)<<endl;
    
    return 0;
}