// #include "./Header/Number.h"

// using namespace std;

// int main()
// {
//     Number<long long> obj(10);
//     cout << obj.mul(17, 23) << '\n';

//     return 0;
// }

// #include "Header/debug.h"

// using namespace std;

// int main()
// {
//     int n = 10;
//     bug(n);
//     return 0;
// }

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix<long long, 2> obj;
    obj = {
        {1, 1},
        {1, 0}
    };
    obj = obj*10 ;

    // obj = obj ^ 10;
    cout << obj.m[1][0] << '\n';

    return 0;
}
