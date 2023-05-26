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

// #include "Matrix.h"

// using namespace std;

// int main()
// {
//     Matrix<long long, 2> obj;
//     obj = {
//         {1, 1},
//         {1, 0}};
//     obj = obj ^ 5;

//     // obj = obj ^ 10;
//     for (int i = 0; i < 2; ++i)
//     {
//         for (int j = 0; j < 2; ++j)
//             cout << obj.m[i][j] << ' ';
//         cout << '\n';
//     }

//     return 0;
// }

// #include "Recurrence.h"

// using namespace std;


// int main()
// {
//     int b[] = {1, 1};
//     int c[] = {1, 1};
//     Recurrence<int, 2> obj(b, c);
//     cout << obj.getNthTerm(235) << '\n';
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int main(int argc, char const *argv[])  // argument count, argument string and agrument of main function
// {
//     cout<<argc<<'\n';
//     for(int i=0;i<argc;++i)
//         cout<<argv[i]<<'\n';
//     return 0;
// }