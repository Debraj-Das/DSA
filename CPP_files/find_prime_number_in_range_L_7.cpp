#include <iostream>
#include <cmath>
using namespace std;

long long int input_a()
{
    long long int a;
    do
    {
        cin >> a;
    } while (a < 0);
    if (a % 2 == 0)
        ++a;
    return a;
}

long long int input_b()
{
    long long int a;
    cin >> a;
    if (a % 2)
        ++a;
    return a;
}

int main()
{
    register long long int a;
    cout << "\nEnter lower positive  teminal(a) :: ";
    a = input_a();
    cout << "\nEnter higher terminal(b) :: ";
    const long long int b = input_b();
    cout << "\nPrime number are in between [ " << a << " , " << b << " ] ::" << endl;
    switch (a)
    {
    case 0:
    case 1:
    case 2:
        cout << "\t" << 2 << endl;
    case 3:
    {
        cout << "\t" << 3 << endl;
        a = 5;
    }
    }
    int prime_numer= 0 ;
    for (register int i, n; a < b; a += 2)
    {
        n = sqrt(a);
        for (i = 3; i <= n; i += 2)
        {
            if (a % i == 0)
            {
                i = 0 ;
                break;
            }
        }
        if (i)
            {
                cout << "\t" << a << endl;
                ++prime_numer ;
            }
    }
    cout<<"\nTotal prime number is "<<prime_numer<<endl ;
    cout << "\nComputation is finished" << endl;
    return 0;
}