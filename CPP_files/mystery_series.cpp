#include <iostream>
#include <ctime>
using namespace std;

void mystery_series()
{
    static int t = time(NULL) % 100;
    while (t % 100)
    {
        ++t;
        if ((t % 3) == 0)
            continue;
        if ((t % 2) == 0)
            t += 3;
        else
            t -= 3;
        cout << t << endl;
    }
    t += (t % 10 + 2);
    return;
}

int main()
{
    cout << "\n\n Print a mystery series :" << endl
         << "--------------------------" << endl
         << "The series are : " << endl;

    mystery_series();

    return 0;
}