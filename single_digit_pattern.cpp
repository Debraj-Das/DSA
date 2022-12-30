#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Make a rectangular shapeby a single digit number :"<<endl
        <<"------------------------------------------"<<endl;
    register int a , i , j ;
    cout<<"Input the number : ";
    cin>>a;
    for(i=0;i<6;++i)
    {
        for(j=0;j<4;++j)
            (j==0||j==2||i==0||i==5)?cout<<a:cout<<" ";
        cout<<endl;  
    }
    return 0;
}