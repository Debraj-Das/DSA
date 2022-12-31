#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter any three number for finding max among them::\n";
    cin >> a >> b >> c;
    if (b > c)
    {
        if (b > a)
        {
            cout << b << " is max amongs input." << endl;
        }
        else
        {
            cout << a << " is max amongs input." << endl;
        }
    }
    else
    {
        if (c > a)
        {
            cout << c << " is max amongs input." << endl;
        }
        else
        {
            cout << a << " is max amongs input." << endl;
        }
    }
   cout<<"\nComputation is finished"<<endl ;
    return 0;
}