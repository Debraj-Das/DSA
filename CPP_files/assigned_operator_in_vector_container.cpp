// vector assignment
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> foo(3, 0);
    std::vector<int> bar(5, 0);

    bar = foo;                //*  assign operator in vector STL.
    foo = std::vector<int>(); //@ similare here declear a new vector and assign it.

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
    return 0;
}