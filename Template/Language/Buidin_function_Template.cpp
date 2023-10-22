#include <bits/stdc++.h>
using namespace std;

// sum function for variadic template
int sum()
{
    return 0;
}
template <typename T, typename... Args> auto sum(T a, Args... args)
{
    return a + sum(args...);
}

// general form of for loop
#define f(i, begin, end)                                                                                               \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << __gcd(18, 27) << endl;          // it give the gcd of the arguments
    cout << __builtin_ffs(10) << endl;      // give position of least signifient 1 bits
    cout << __builtin_clz(16) << endl;      // no of 0 before most significents bit
    cout << __builtin_ctz(16) << endl;      // no of 0 after the least significents bit
    cout << __builtin_popcount(14) << endl; // it give the no of 1 bit of that number
    cout << sum(3, 31, 51, 52) << endl;

    int arr[] = {23, 23, 131, 141, 51};
    f(j, 5, 0) cout << arr[j] << ' ';
    cout << '\n';

    string r_str =
        R"(Dear Programmers,
    I'm using C++11
    Regards, Swift!)";
    cout << r_str << endl;

    return 0;
}